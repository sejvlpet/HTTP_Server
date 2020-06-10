#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include <utility>
#include <sys/stat.h>
#include "server.h"
#include "parser.h"
#include "request.h"
#include "response.h"
#include "dirResponse.h"
#include "fileResponse.h"
#include "execResponse.h"
#include "notFoundResponse.h"
#include "helper.h"
#include "byeResponse.h"


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
