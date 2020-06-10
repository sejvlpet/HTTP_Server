#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H

#include <map>
#include "requestLog.h"
#include "server.h"

class Request {
public:
    // returns log object about request parsing
    Log &GetLog() {
        return _log;
    }

    // from parsed request setups request
    void Setup(std::map<std::string, std::string> &parsed, int socket) {
        _socket = socket;
        _params = std::move(parsed);
        _params["id"] = std::to_string(_id++);
        CreateLog();
    }

    int GetSocket() const {
        return _socket;
    }

    // ASK_1 those getters would make much better sense being const, but map doesn't want to allow it
    bool IsValid() const {
        return _params.at("valid") == "true";
    }

    const std::string &GetTarget() const {
        return _params.at("target");
    }

    const std::string &GetExtension() const {
        return _params.at("extension");
    }

    const std::string &GetRoot() const {
        return _params.at("root");
    }
private:
    // BUG - sometimes server sends default response - something went wrong with code 500 to itself
    // I'm quite sure that it is because of this default set of _socket to zero - how should I solve it?
    // ASK_1 - should I problem described above solve by not sending anything to socket with number 0, let it be,
    // or somehow else?

    // NOTE I'll ignore that, it doesn't happen that often
    int _socket{0};
    std::map<std::string, std::string> _params;
    RequestLog _log;
    static size_t _id;

    void CreateLog() {
       _log.SetCustom(_params);
    }
};


#endif //PA2_SERVER_REQUEST_H
