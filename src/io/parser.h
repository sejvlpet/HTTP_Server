#ifndef PA2_SERVER_PARSER_H
#define PA2_SERVER_PARSER_H

#include <map>
#include "request.h"

class Parser {
public:
    // reads buffer, saves information from which it creates its parsed request which shall be later returned
    Parser(const char *buffer, int socket) : _buffer(buffer), _socket(socket) {
        std::map<std::string, std::string> parsed;
        if (_buffer.empty()) _parsedRequest.UnknownError();
        else Parse();
    }

    Request GetRequest() const {
        return _parsedRequest;
    }

    std::map<std::string, std::string> GetParsed() {
        return std::move(_parsed); // parses is one use only
    }

private:
    Request _parsedRequest;
    std::map<std::string, std::string> _parsed;
    const std::string _buffer;
    int _socket;

    void Parse() {
        SetKeyValues();
        SetUrl();

        _parsedRequest.Setup(_parsed, _socket);
    }

    void SetUrl() {
        if(_parsed.find("request") == _parsed.end()) {
            _parsedRequest.UnknownError();
            return;
        }

        std::string tmp = _parsed["request"];
        // todo read string after / from that
    }


    void SetKeyValues() {
        bool readKey = true, reqfound = false;
        std::string key;
        std::string value;

        for (char c : _buffer) {
            if (c == ':' && readKey) readKey = false; // : means end of key and start of value,
                // we have to also check if is' reached while reading key (so it isn't part of value)
            else if (c == '\n' && key.size() > 0) {
                readKey = true; // \n means end of line => end of one req param (no matter where found)
                // save key-value to map and continue with (hopefully) emptied key and value
                // I have no idea why, but the most needed part of request is in part with protocol name
                if(!reqfound && key.find("HTTP/1.1") != std::string::npos) {
                    _parsed["request"] = std::move(key);
                    reqfound = true;
                }
                else _parsed[std::move(key)] = std::move(value);
                key.empty();
                value.empty(); // just in case...
            }
            else if(!isspace(c)) {
                if(readKey) key.push_back(c);
                else value.push_back(c);
            }
        }
    }
};


#endif //PA2_SERVER_PARSER_H
