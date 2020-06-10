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
    return _params.at("valid") == "true";
}

const std::string &Request::GetTarget() const {
    return _params.at("target");
}

const std::string &Request::GetExtension() const {
    return _params.at("extension");
}

const std::string &Request::GetRoot() const {
    return _params.at("root");
}

void Request::CreateLog() {
    _log.SetCustom(_params);
}
