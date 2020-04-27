#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <thread>
#include "../../helper.h"
#include "server.h"
#include "worker.h"
#include "../log/shutdownLog.h"
#include "../log/errorLog.h"
#include "../logger/consoleLogger.h"
#include "../logger/fileLogger.h"

void Server::Error(const std::string &message) {
    Log(ErrorLog(message));
    _setupStatus = FAIL;
    _shutDown = true; // in case of error in the future
    // maybe I should also sets workers to 0 so server really quits
}

void Server::ReadOptions(const std::string &configFileName) {
    std::string response, tmp;
    std::ifstream file(configFileName);
    std::map<std::string, std::string> options;

    if (!file.is_open()) {
        Error("Couldn't open file with options");
        return;
    }

    // read config line by line, and save as key-values pair splitted by :
    while (std::getline(file, tmp)) {
        size_t delimeterPos = tmp.find(':');
        if (delimeterPos == std::string::npos) {
            // error log? warning log? Idk, will see
            Error("Invalid options");
            return; // or not?
        }
        options[tmp.substr(0, delimeterPos)] = tmp.substr(delimeterPos + 1);
    }

    file.close();
    SetupOptions(options);
}

void Server::SetupOptions(std::map<std::string, std::string> &options) {
    for (auto &pair: options) {
        std::string key = pair.first;
        std::string value = pair.second;
        if (_options.find(key) != _options.end()) {
            if (key == "port") {
                if (std::stoi(value) > 65535 || std::stoi(value) < 1024) {
                    Error("Invalid port number");
                    return;
                }
            } else if (key == "root") {
                // todo check accesibility
            } else if (key == "logLocation") {
                if (_locations.find(value) == _locations.end()) {
                    Error("Unknown log location value");
                    return;
                }
            } else if (key == "logLevel") {
                if (_levels.find(value) == _levels.end()) {
                    Error("Unknown log level value");
                    return;
                }
            } else if (key == "logFile") {
                // todo check rights
            } else if (key == "shutDownUrl") {
                Error("Trying to set system option");
                return;
            }
            _options[key] = value; // if everything's fine, set readed value
        } else {
            Log(ErrorLog("Trying to set invalid option " + key + " with value " + value, false));
        }
    }
}

void Server::Setup() {
    if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        Error("Problem with socket");
        return;
    }
    _addrLen = sizeof(_address);

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(std::stoi(_options["port"]));

    // fixme do something more c++
    memset(_address.sin_zero, '\0', sizeof(_address.sin_zero));

    // fixme this has to change
    const int trueFlag = 1;
    if (setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0) {
        Error("Error in setsockopt");
        return;
    }

    // fixme this has to change
    if (bind(_serverFd, (struct sockaddr *) &_address, sizeof(_address)) < 0) {
        Error("Error in bind");
        return;
    }
    if (listen(_serverFd, 10) < 0) {
        // fixme log error
        Error("Error in listen");
        _setupStatus = FAIL;
        return;
    }

    if (_locations[_options["logLocation"]] == FILE) { // console is there by default
        _logger = std::make_unique<FileLogger>();
    }

    _setupStatus = OK;
}

void Server::ShutDown() {
    Log(ShutDownLog(false));
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
                Error("Error in accept");
                return LISTEN_FAIL;
            }
            if (_workersCount < std::stoi(_options["maxPendingRequests"])) {
                Worker worker(this, newSocket);
                worker.Run();
            } else {
                Log(ErrorLog("Couldn't handle request", false));
            }
        }

        // fixme - this condition doesn't obviously work :D
        if (_shutDown && _workersCount == 0) break;
    }
    // fixme log shutting down
    Log(ShutDownLog(true));
    return LISTEN_SUCCESS;
}
