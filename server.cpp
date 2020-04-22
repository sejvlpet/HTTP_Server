#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <thread>
#include "helper.h"
#include "server.h"


// todo - as there'll be loads of const and messages like that, I'd like to keep them in seperate file shared over more classes
const char *Server::WAIT = "wait";
int Server::_workersCount{0};
const std::set<std::string> Server::IGNORE_LIST {"favicon.ico"};


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
    _setupStatus = OK;
}

int Server::Listen() {
    if(_setupStatus == SETUP_STATUS::FAIL) return SETUP_FAIL;

    while (true) {
        int newSocket;
        // fixme do something more c++

        if(!_shutDown) {
            if ((newSocket = accept(_serverFd, (sockaddr *) &_address, (socklen_t *) &_addrLen)) < 0) {
                // listening failed
                perror("In accept");
                return LISTEN_FAIL;
            }
            std::thread thr(Response, newSocket);
            thr.detach();
        } else if(_workersCount == 0) return LISTEN_OK;
    }
}























// fixme add some logic
// will throw exceptions if something happens
// entire response could be another class, at lest I wouldn't have to pass that socket number all the time
void Server::Response(int socket) {
    std::cout << "currently running " << ++_workersCount << " threads\n";
    char buffer[BUFFER_READ_SIZE] = {0};
    read(socket, buffer, BUFFER_READ_SIZE);

    ProcessMessage(socket, buffer);
    close(socket);
    std::cout << "currently running " << --_workersCount << " threads\n";
}


int Server::ProcessMessage(int socket, char buffer[BUFFER_READ_SIZE]) {
    std::string req = GetReq(buffer);
    if(IGNORE_LIST.find(req) != IGNORE_LIST.end())
        return IGNORE;

    if(req == "THREAD_TEST") {
        std::cout << "thread tested with " << _workersCount << " running workers\n";
        std::string response = "TEST_PASSED-" + std::to_string(_workersCount);
        const char *success = response.c_str();
        write(socket, success, strlen(success));
        Helper::Wait(5000000000);
        return SUCCESS;
    }


    std::cout << req << '\n';
    write(socket, HELLO, strlen(HELLO));
    if(req == WAIT) Helper::Wait();
    return SUCCESS;
}

// fixme needs rename
std::string Server::GetReq(char buffer[BUFFER_READ_SIZE]) {
    if(!strcmp(buffer,"THREAD_TEST")) {
        return "THREAD_TEST";
    }

    std::string res;
    size_t i = 0;
    while(i < BUFFER_READ_SIZE && buffer[i++] != '/'){}
    while(i < BUFFER_READ_SIZE && buffer[i] != ' ') {
        res.push_back(buffer[i++]);
    }
    if(i == BUFFER_READ_SIZE) {
        // this shouldn't happen, but lets be paranoid and throw something here (in the future)
        std::cout << "this shouldn't have happend\n";
        std::cout << buffer << '\n';
    }
    return res;
}