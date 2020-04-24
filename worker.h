#ifndef PA2_SERVER_WORKER_H
#define PA2_SERVER_WORKER_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include "server.h"
#include "controller.h"
#include "parser.h"
#include "request.h"

// parses message and let controller handle it in it's own thread
class Worker {
public:
    static const int BUFFER_READ_SIZE{300000};

    // fixme move this to cpp file
    Worker(Server *parent, int socket) : _parent(parent), _socket(socket) {
        // read
        read(socket, _buffer, BUFFER_READ_SIZE);
        ParseMessage();
    }


    // tohle se musi vymyslet, je potreba aby odsud controller veci poresil ve vlastnim threadu, takze
    // prislusna metoda musi byt static, nejsem si jistej jak moc dobre to ted pujde
    int Run() {
        // todo run in thread

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
        Parser parser(_buffer);
        _request = parser.GetRequest(_socket);
        _parent->Log(_request.GetLog());
    }
};


#endif //PA2_SERVER_WORKER_H
