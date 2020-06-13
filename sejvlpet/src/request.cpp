#include "request.h"

size_t Request::_id = 0;

Log &Request::GetLog() {
    return _log;
}

void Request::Setup(std::map<std::string, std::string> &parsed, int socket) {
    _socket = socket;
    _params = std::move(parsed);
    _params["id"] = std::to_string(_id++);
    CreateLog();
}

int Request::GetSocket() const {
    return _socket;
}


bool Request::IsValid() const {
    try {
        return _params.at("valid") == "true";
    } catch (...) {
        return false;
    }
}

const std::string &Request::GetTarget() const {
    try {
        return _params.at("target");
    } catch (...) {
        return _invalidKeyVal;
    }
}

const std::string &Request::GetExtension() const {
    try {
        return _params.at("extension");
    } catch (...) {
        return _invalidKeyVal;
    }
}

const std::string &Request::GetRoot() const {
    try {
        return _params.at("root");
    } catch (...) {
        return _invalidKeyVal;
    }
}

void Request::CreateLog() {
    _log.SetCustom(_params);
}
