#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include <cstring>
#include <unistd.h>
#include "request.h"
#include "helper.h"

class Controller {
public:
    void operator() (const Server *parent, Request request) {
        _parent = parent;
        _request = request;


        // todo add some logic round responses
        HandleRequest();
    }

private:
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!"};
    const Server *_parent{nullptr};
    Request _request;


    void HandleRequest() {
        _parent->IncWorkers();
        std::cout << "Hi, I'm controller and right now I'm doing something very useless, but at least something\n";
        Log tmp;
        _parent->Log(tmp);
        write(_request._socket, HELLO, strlen(HELLO));
        // Helper::Wait();
        _parent->DecWorkers();
    }
};


#endif //PA2_SERVER_CONTROLLER_H
