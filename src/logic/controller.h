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
    Server *_parent{nullptr};
    Request _request;
    std::unique_ptr<Response> _response{new Response()}; // fixme I don't like that unique_ptr

    void HandleRequest() {
        std::string target = _request.GetTarget();

        _parent->IncWorkers();

        // Helper::Wait();
        if (!_request.IsValid()) {
            // _response = GetInvalid...
        } else if (target.empty()) { // no target given => writeOut index.Html
            // todo check if do we have right to read index.html
            _response = std::make_unique<FileResponse>(); // set response to write out index.html
        } else if (_parent->ShutDownCalled(target)) {
            _parent->ShutDown();
            // todo check if do we have right to read
            _response = std::make_unique<FileResponse>("bye.html");
        } else {
            // todo handle other requests - concrete files, folders, executable and so on
        }

        _response->WriteOut(_request.GetSocket());
        _parent->Log(_response->GetLog());

        close(_request.GetSocket());
        _parent->DecWorkers();
    }
};


#endif //PA2_SERVER_CONTROLLER_H
