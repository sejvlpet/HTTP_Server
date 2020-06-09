#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <thread>
#include "request.h"
#include "fileResponse.h"
#include "dirResponse.h"
#include "execResponse.h"
#include "notFoundResponse.h"
#include "parser.h"
#include "worker.h"
#include "threadPool.h"



// todo here should be implemented thread pool


// parses message and let controller handle it in it's own thread
class Controller {
public:
    static const size_t BUFFER_READ_SIZE{300000};

    // fixme move this to cpp file
    Controller(Server *parent, size_t maxThreads) : _parent(parent), _threadPool(maxThreads) {}

    void Run(int socket) {
        read(socket, _buffer, BUFFER_READ_SIZE);
        Request request =  ParseMessage(socket);

        _threadPool.enqueue<Worker>(Worker(_parent, request));

    }

private:
    Server *_parent{nullptr};
    char _buffer[BUFFER_READ_SIZE]{0};
    ThreadPool _threadPool;

    // fixme move this to cpp file
    // Parse message and saves it as request object
    Request ParseMessage(int socket) {
        // create instance of parser and give it _request to parse, returns
        Parser parser(_buffer, socket, _parent->GetRoot()); // parses request, creates its own instance of request
        Request request = parser.GetRequest(); // here is request instance moved from parser
        _parent->Log(request.GetLog()); // log things
        return request;
    }
};


#endif //PA2_SERVER_CONTROLLER_H
