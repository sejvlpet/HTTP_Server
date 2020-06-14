#include "parser.h"


Parser::Parser(const char *buffer, int socket, std::string root) : _buffer(buffer), _socket(socket),
                                                                   _root(std::move(root)) {
    std::map<std::string, std::string> parsed;
    if (_buffer.empty()) _parsed["valid"] = "false";
    else Parse();
}

Request Parser::GetRequest() {
    return std::move(_parsedRequest); // parses is one use only
}

void Parser::Parse() {
    _parsed["valid"] = "true";
    SetKeyValues();
    SetTarget();
    GetExtension();

    std::string add = (!_root.empty() && _root[_root.size() - 1] != '/') ?  "/" : "";
    _parsed["root"] = _root + add;

    // notice that _parsed is moved to setup and therefore destroyed here
    _parsedRequest.Setup(_parsed, _socket);
}

void Parser::SetTarget() {
    if (_parsed.find("request") == _parsed.end()) {
        _parsed["valid"] = "false";
        return;
    }

    std::string tmp = _parsed["request"];
    size_t start = tmp.find('/') + 1;
    size_t end = tmp.find_last_of('H'); // finds last H => it's part of protocol name

    // target will always be searched in root directory
    _parsed["target"] = tmp.substr(start, end - start);
}

void Parser::GetExtension() {
    if (_parsed.find("target") == _parsed.end()) { // this is a little paranoid
        _parsed["valid"] = "false";
        return;
    }

    std::string tmp = _parsed["target"];
    size_t start = tmp.find('.') + 1;

    if (start - 1 == std::string::npos) _parsed["extension"] = "";
    else _parsed["extension"] = tmp.substr(start);
}

void Parser::SetKeyValues() {
    bool readKey = true, reqfound = false;
    std::string key;
    std::string value;

    for (char c : _buffer) {
        if (c == ':' && readKey) readKey = false; // : means end of key and start of value,
            // we have to also check if is reached while reading key (so it isn't part of value)
        else if (c == '\n' && !key.empty()) {
            readKey = true; // \n means end of line => end of one req param (no matter where found)
            // save key-value to map and continue with emptied key and value
            // I have no idea why, but the most needed part (at least for me) of request is in part with protocol name
            // and has to be operated out like that
            if (!reqfound && key.find("HTTP/1.1") != std::string::npos) {
                _parsed["request"] = std::move(key);
                reqfound = true;
            } else _parsed[std::move(key)] = std::move(value);
            key.erase();
            value.erase(); // just in case...
        } else if (!isspace(c)) {
            if (readKey) key.push_back(c);
            else value.push_back(c);
        }
    }
}
