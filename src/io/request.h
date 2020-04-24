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
    std::unique_ptr<Log> GetLog(){
        RequestLog tmp;
        return std::make_unique<RequestLog>(tmp);
    }
};


#endif //PA2_SERVER_REQUEST_H
