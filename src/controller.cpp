#include "controller.h"
#include "parser.h"
#include "errorLog.h"


Controller::Controller(Server *parent, size_t maxThreads, size_t maxQueue) : _parent(parent), _threadPool(maxThreads),
                                                                             _maxQueue(maxQueue) {}

void Controller::Run(int socket) {
    read(socket, _buffer, BUFFER_READ_SIZE);
    Request request = ParseMessage(socket);

    if (_threadPool.GetCountOfQueued() <= _maxQueue)
        _threadPool.Enqueue<Worker>(Worker(_parent, request));
    else
        _parent->Log(ErrorLog("Request timeouted due to full queue", false));
}

Request Controller::ParseMessage(int socket) {
    // create instance of parser and give it _request to parse
    Parser parser(_buffer, socket, _parent->GetRoot()); // parses request, parser creates its own instance of request
    Request request = parser.GetRequest(); // here is request instance moved from parser
    _parent->Log(request.GetLog());
    return request;
}
