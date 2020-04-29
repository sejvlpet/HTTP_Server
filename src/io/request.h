#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H

#include <map>
#include "../log/requestLog.h"
#include "../logic/server.h"

class Request {
public:
    // returns log object about request parsing
    // as request log will be always obtained in same thread where it is created, we can afford to pass it as ref
    // anyway, maybe I'll change it to unique_ptr to have that same as in respsonse class
    // where I have no choice but unique_ptr
    Log &GetLog() {
        return _log;
    }

    // from parsed request setups request
    void Setup(std::map<std::string, std::string> &parsed, int socket) {
        _socket = socket;
        _params = std::move(parsed); // nobody cares about parsers ownership lol
        _params["id"] = std::to_string(_id++);
        CreateLog();
    }

    int GetSocket() const {
        return _socket;
    }

    bool IsValid() {
        return _params["valid"] == "true";
    }

    const std::string &GetTarget() {
        return _params["target"];
    }

    const std::string &GetExtension() {
        return _params["extension"];
    }

    const std::string &GetRoot() {
        return _params["root"];
    }
private:
    int _socket{0}; // fixme deafult value  seems  wrong - but isn't unutilised (or how to spell it) even worse?
    std::map<std::string, std::string> _params;
    RequestLog _log;
    static size_t _id;

    void CreateLog() {
       _log.SetCustom(_params);
    }
};


#endif //PA2_SERVER_REQUEST_H
