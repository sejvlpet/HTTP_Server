#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <thread>
#include "helper.h"
#include "server.h"
#include "worker.h"


// todo - as there'll be loads of const and messages like that, I'd like to keep them in seperate file shared over more classes
const std::set<std::string> Server::IGNORE_LIST{"favicon.ico"};


Server::Server() {
    Setup();
}


void Server::Setup() {
    if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        _setupStatus = FAIL;
        return;
    }
    _addrLen = sizeof(_address);

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(_port);

    // fixme do something more c++
    memset(_address.sin_zero, '\0', sizeof(_address.sin_zero));

    // fixme this has to change
    const int trueFlag = 1;
    if (setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0) {
        _setupStatus = FAIL;
        return;
    }

    // fixme this has to change
    if (bind(_serverFd, (struct sockaddr *) &_address, sizeof(_address)) < 0) {
        perror("In bind");
        _setupStatus = FAIL;
        return;
    }
    if (listen(_serverFd, 10) < 0) {
        perror("In listen");
        _setupStatus = FAIL;
        return;
    }

    if (_logLocation == CONSOLE) {
        _logger = std::make_unique<ConsoleLogger>();
    } else {
        _logger = std::make_unique<FileLogger>();
    }

    _setupStatus = OK;
}

void Server::ShutDown() {
    Log(std::make_unique<ShutDownLog>(false));
    _shutDown = true;
}

int Server::Listen() {
    if (_setupStatus == SETUP_STATUS::FAIL) return SETUP_FAIL;

    while (true) {
        if (!_shutDown) { // after shutdown any request won't be accepted
            int newSocket;
            // fixme do something more c++
            if ((newSocket = accept(_serverFd, (sockaddr *) &_address, (socklen_t *) &_addrLen)) < 0) {
                // listening failed
                perror("In accept");
                return LISTEN_FAIL;
            }
            Worker worker(this, newSocket);
            worker.Run();
        }

        // fixme - this condition doesn't obviously work :D
        if(_shutDown && _workersCount == 0) break;
    }
    // fixme log shutting down
    Log(std::make_unique<ShutDownLog>(true));
    return LISTEN_SUCCESS;
}
