#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include "server.h"
#include "controller.h"
#include "../io/parser.h"
#include "../io/request.h"

// parses message and let controller handle it in it's own thread
class Worker {
public:
    static const size_t BUFFER_READ_SIZE{300000};

    // fixme move this to cpp file
    Worker(Server *parent, int socket) : _parent(parent), _socket(socket) {
        // read
        read(socket, _buffer, BUFFER_READ_SIZE);
        ParseMessage();
    }


    int Run() {

        std::thread thr(Controller(), _parent, _request);
        thr.detach();

        // fixme return something real
        return 1;
    }

private:
    Server *_parent{nullptr};
    char _buffer[BUFFER_READ_SIZE]{0};
    int _socket;
    Request _request;

    // fixme move this to cpp file
    // Parse message and saves it as request object
    void ParseMessage() {
        // create instance of parser and give it _request to parse, returns
        Parser parser(_buffer, _socket); // parses request, creates its own instance of request
        _request = parser.GetRequest(); // here is request instance mover from parser
        _parent->Log(_request.GetLog()); // log things
    }
};


#endif //PA2_SERVER_WORKER_H
