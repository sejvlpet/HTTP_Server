#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H
#include "log.h"
#include "server.h"

class Request {
public:
    int _socket{0}; // fixme deafult value for socket seems really wrong
    Request()= default;
    Request(int socket) : _socket(socket) {}

    // returns log object about request parsing
    Log GetParseLog() const {
        Log tmp;
        return tmp;
    }

    // returns log object about request sending
    Log GetSendLog() const {
        Log tmp;
        return tmp;
    }
};


#endif //PA2_SERVER_REQUEST_H
