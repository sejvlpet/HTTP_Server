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


// parses message and let controller handle it in it's own thread
class Controller {
public:
    static const size_t BUFFER_READ_SIZE{300000};

    // fixme move this to cpp file
    Controller(Server *parent, int socket) : _parent(parent), _socket(socket) {
        // read
        read(socket, _buffer, BUFFER_READ_SIZE);
        ParseMessage();
    }

    void Run() {

        std::thread thr(Worker(), _parent, _request);
        thr.detach();

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
        Parser parser(_buffer, _socket, _parent->GetRoot()); // parses request, creates its own instance of request
        _request = parser.GetRequest(); // here is request instance mover from parser
        _parent->Log(_request.GetLog()); // log things
    }
};


#endif //PA2_SERVER_CONTROLLER_H
