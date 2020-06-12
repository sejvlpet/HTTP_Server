#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include "server.h"
#include "request.h"
#include "response.h"

/**
 * Takes care of sending proper response back
 */
class Worker {
public:
    /**
     * storer informations
     * @param parent pointer to parent server
     * @param request request to be responed
     */
    Worker(Server *parent, Request request);

    /**
     * Invokes request processing
     */
    void operator()();

private:
    Server *_parent{nullptr}; //<! poiner to parent server
    Request _request; //<! request to be processed
    std::unique_ptr<Response> _response{std::make_unique<Response>()}; //<! proper response

    /**
     * Handles request and sends proper response back
     */
    void HandleRequest();

};

#endif //PA2_SERVER_WORKER_H
