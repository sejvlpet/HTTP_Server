#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H

#include <map>
#include "../log/requestLog.h"
#include "../logic/server.h"

class Request {
public:
    // returns log object about request parsing
    // as request log will be always obtained in same thread where it is created, we can afford to pass it as ref
    // anyway, maybe I'll change it to unique_ptr to have that same as in resonse class
    // where I have no choice but unique_ptr
    Log &GetLog() {
        return _log;
    }

    // from parsed request setups request
    void Setup(std::map<std::string, std::string> &parsed, int socket) {
        _isValid = true;
        _socket = socket;
        _params = std::move(parsed); // nobody cares about parsers ownership lol
        CreateLog();
    }

    void Error() {
        _isValid = false;
    }

    int GetSocket() const {
        return _socket;
    }

private:
    int _socket{0}; // fixme deafult value  seems  wrong - but isn't unutilised (or how to spell it) even worse?
    bool _isValid{true};
    std::map<std::string, std::string> _params;
    RequestLog _log;

    void CreateLog() {
        if(_isValid) _log.SetCustom(_params);
        else _log.SetInvalid();
    }
};


#endif //PA2_SERVER_REQUEST_H
