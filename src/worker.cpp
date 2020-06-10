#include "worker.h"

Worker::Worker(Server *parent, Request request) : _parent(parent), _request(std::move(request)) {}

void Worker::operator()() {
    HandleRequest();
}

void Worker::HandleRequest() {
    // todo refactor
    std::string target = _request.GetTarget();
    std::string extension = _request.GetExtension();
    std::string root = _request.GetRoot();

//    if(target[target.size() - 1 ] == '/')
//        target.pop_back();

    _parent->IncWorkers();


    if (_request.IsValid()) {

        if (target.empty()) {

            _response = std::make_unique<DirResponse>(root);

        } else if (_parent->ShutDownCalled(target)) {

            _parent->ShutDown();
            _response = std::make_unique<ByeResponse>();

        } else if (dirExists(root + '/' + target)) {

            _response = std::make_unique<DirResponse>(root + target);

        } else if (isExecutable(root + '/' + target)) {

            _response = std::make_unique<ExecResponse>(root, target);

        } else if (fileOk(root + '/' + target)) {
            if (extension == "html") {
                _response = std::make_unique<FileResponse>(root, target);
            } else {
                _response = std::make_unique<FileResponse>(root, target, false);
            }
        } else {
            if (target == "testThread") {
                // although this branch is for testing purposes only, I believe that this testing is essential
                sleep(10);
            }
            _response = std::make_unique<NotFoundResponse>();

        }
    }

    _response->WriteOut(_request.GetSocket());
    close(_request.GetSocket());
    _parent->DecWorkers();

    _parent->Log(_response->GetLog());
}
