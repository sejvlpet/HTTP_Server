#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include <cstring>
#include <unistd.h>
#include "../io/request.h"
#include "../../helper.h"
#include "../io/response/fileResponse.h"
#include "../io/response/dirResponse.h"

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
    std::unique_ptr<Response> _response{std::make_unique<Response>()}; // fixme I don't like that unique_ptr

    void HandleRequest() {
        std::string target = _request.GetTarget();
        std::string extension = _request.GetExtension();
        std::string root = _request.GetRoot();

        _parent->IncWorkers();

        // todo check rights and permisions
        // this version recently fails if trying to read nonexistng folder and returns nothing for
        // not existing file

        if (!_request.IsValid()) {
            // _response = GetInvalid...
        } else if (target.empty()) { // no target given => writeOut index.Html
            _response = std::make_unique<DirResponse>(root);
        } else if (_parent->ShutDownCalled(target)) {
            _parent->ShutDown();
            _response = std::make_unique<FileResponse>(root, "bye.html");
        } else if(extension.empty()) { // no extension, but some target there is
            _response = std::make_unique<DirResponse>(root + target);
        } else if(extension == "html" || extension == "txt") {
            _response = std::make_unique<FileResponse>(root, target); // set response to write out index.html
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
