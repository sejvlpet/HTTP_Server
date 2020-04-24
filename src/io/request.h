#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H
#include "../log/requestLog.h"
#include "../logic/server.h"

class Request {
public:
    int _socket{0}; // fixme deafult value for socket seems really wrong
    Request()= default;
    Request(int socket) : _socket(socket) {}

    // returns log object about request parsing
    // as request log will be always obtained in same thread where it is created, we can afford to pass it as ref
    // anyway, maybe I'll change it to unique_ptr to have that same as in resonse class
    // where I have no choice but unique_ptr
    Log &GetLog(){
        return _log;
    }

private:
    RequestLog _log;
};


#endif //PA2_SERVER_REQUEST_H
