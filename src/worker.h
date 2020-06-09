#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include <sys/stat.h>
#include "server.h"
#include "parser.h"
#include "request.h"
#include "response.h"
#include "dirResponse.h"
#include "fileResponse.h"
#include "execResponse.h"
#include "notFoundResponse.h"

// fixme - this class should be named controller a recent controller should be a worker - rename


class Worker {
public:
    Worker(Server *parent, Request request) : _parent(parent), _request(request) {}

    void operator()() {
        HandleRequest();
    }

private:
    Server *_parent{nullptr};
    Request _request;
    std::unique_ptr<Response> _response{std::make_unique<Response>()};

    void HandleRequest() {
        std::string target = _request.GetTarget();
        std::string extension = _request.GetExtension();
        std::string root = _request.GetRoot();

        _parent->IncWorkers();


        if (_request.IsValid()) {

            if (target.empty()) {

                _response = std::make_unique<DirResponse>(root);

            } else if (_parent->ShutDownCalled(target)) {

                _parent->ShutDown();
                _response = std::make_unique<FileResponse>(root, "bye.html");

            } else if (DirExists(root + '/' + target)) {

                _response = std::make_unique<DirResponse>(root + target);

            } else if (IsExecutable(root + '/' + target)) {

                _response = std::make_unique<ExecResponse>(root, target);

            } else if (FileOk(root + '/' + target)) {
                if (extension == "html") {
                    _response = std::make_unique<FileResponse>(root, target);
                } else {
                    _response = std::make_unique<FileResponse>(root, target, false);
                }
            } else if(target == "testThread") {
                // although this branch is for testing purposes only, I believe that this testing is essential
                sleep(10);
                _response = std::make_unique<NotFoundResponse>();
            } else {

                _response = std::make_unique<NotFoundResponse>();

            }
        }

        _response->WriteOut(_request.GetSocket());
        _parent->Log(_response->GetLog());

        close(_request.GetSocket());
        _parent->DecWorkers();
    }

    // todo - those method has nothing to do with controller - should be only functions and implemented somewhere else

    static bool IsExecutable(const std::string &file) {
        // inspired on https://stackoverflow.com/questions/5719694/how-to-check-if-file-is-executable-in-c
        struct stat st{};

        if (stat(file.c_str(), &st) < 0)
            return false;
        return (st.st_mode & S_IEXEC) != 0;
    }

    static bool DirExists(const std::string &dir) {
        // inspired on https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
        struct stat info{};

        if (stat(dir.c_str(), &info) != 0)
            return false;
        else return (info.st_mode & S_IFDIR) != 0;
    }

    static bool FileOk(const std::string &file) {
        std::ifstream ifile;
        ifile.open(file);
        return ifile && true;
    }
};

#endif //PA2_SERVER_WORKER_H
