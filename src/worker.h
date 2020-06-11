#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include "server.h"
#include "request.h"
#include "response.h"


class Worker {
public:
    Worker(Server *parent, Request request);

    void operator()();

private:
    Server *_parent{nullptr};
    Request _request;
    std::unique_ptr<Response> _response{std::make_unique<Response>()};

    void HandleRequest();

};

#endif //PA2_SERVER_WORKER_H
