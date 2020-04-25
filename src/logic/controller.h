#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include <cstring>
#include <unistd.h>
#include "../io/request.h"
#include "../../helper.h"
#include "../io/response.h"

class Controller {
public:
    void operator() (Server *parent, const Request &request) {
        _parent = parent;
        _request = request;


        // todo add some logic round responses
        HandleRequest();
    }

private:
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!"};
    Server *_parent{nullptr};
    Request _request;
    std::unique_ptr<Response> _response;

    void HandleRequest() {
        _parent->IncWorkers();
        write(_request.GetSocket(), HELLO, strlen(HELLO));
        // Helper::Wait();

        _parent->Log(_response->GetLog());

        _parent->DecWorkers();
    }
};


#endif //PA2_SERVER_CONTROLLER_H
