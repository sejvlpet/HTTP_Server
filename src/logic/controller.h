#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include <cstring>
#include <unistd.h>
#include "../io/request.h"
#include "../../helper.h"
#include "../io/response/response.h"
#include "../io/response/fileResponse.h"

class Controller {
public:
    void operator()(Server *parent, const Request &request) {
        _parent = parent;
        _request = request;
        HandleRequest();
    }

private:
    const constexpr static char *HELLO{"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!"};
    Server *_parent{nullptr};
    Request _request;
    std::unique_ptr<Response> _response{std::make_unique<Response>()}; // fixme I don't like that unique_ptr

    void HandleRequest() {
        _parent->IncWorkers();

        // Helper::Wait();
        if (!_request.IsValid()) {
            // _response = GetInvalid...
        } else if (_request.GetTarget().empty()) { // no target given => writeOut index.Html
            // todo check if do we have right to read index.html
             _response = std::make_unique<FileResponse>(); // set response to write out index.html
        } else {
            // todo handle other requests - concrete files, folders, executable and so on
        }


        // write(_request.GetSocket(), HELLO, strlen(HELLO));

//        _response->WriteOut(_request.GetSocket());
         _response->WriteOut(_request.GetSocket());
        _parent->Log(_response->GetLog());
        close(_request.GetSocket());
        _parent->DecWorkers();
    }
};


#endif //PA2_SERVER_CONTROLLER_H
