#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include "server.h"
#include "shutdownLog.h"
#include "errorLog.h"
#include "consoleLogger.h"
#include "fileLogger.h"
#include "controller.h"


Server::Server() {
    // setups logger to default - console with default logFormat
    // this step is needed for errors in setup to be logged
    _logger = std::make_unique<ConsoleLogger>(_options["logFormat"]);
}

bool Server::ShutDownCalled(const std::string &reqUrl) const {
    return _options.at("shutdownUrl") == reqUrl || _options.at("userDefinedShutdownUrl") == reqUrl;
}

void Server::Error(const std::string &message) {
    Log(ErrorLog(message));
    _setupStatus = FAIL;
    _shutDown = true; // in case of error in the future
}

void Server::ReadOptions(const std::string &configFileName) {
    std::string response, tmp;
    std::ifstream file(configFileName);
    std::map<std::string, std::string> options;

    if (!file.is_open()) {
        Error("Couldn't open file with options");
        return;
    }

    // read config line by line, and save as key-values pair seperated by :
    while (std::getline(file, tmp)) {
        if (!tmp.empty() && tmp[0] != COMMENT) {
            size_t delimeterPos = tmp.find(DELIMETER);
            if (delimeterPos == std::string::npos) {
                Error("Invalid options");
                return;
            }
            options[tmp.substr(0, delimeterPos)] = tmp.substr(delimeterPos + 1);
        }
    }

    file.close();
    SetupOptions(options);
}

void Server::SetupOptions(const std::map<std::string, std::string> &options) {
    for (const auto &pair: options) {
        const std::string &key = pair.first;
        const std::string &value = pair.second;
        if (_options.find(key) != _options.end()) {
            if (key == "port") {
                if (std::stoi(value) > 65535 || std::stoi(value) < 1024) {
                    Error("Invalid port number");
                    return;
                }
            } else if (key == "logLocation") {
                if (_locations.find(value) == _locations.end()) {
                    Error("Unknown log location value");
                    return;
                }
            } else if (key == "shutDownUrl") {
                Error("Trying to set system option");
                return;
            } else if (key == "maxThreads" || key == "maxQueue") {
                if (std::stoi(value) <= 0) {
                    Error("Trying to set invalid count of threads or invalid queue size");
                    return;
                }
            }

            _options[key] = value; // if everything's fine, set loaded value
        } else {
            Log(ErrorLog("Trying to set invalid option \"" + key + "\" with value \"" + value + "\"", false));
        }
    }

    // NOTE - is it enough like that? Or should I test accessibility and shit?
    // root is tested outside of loop, because even that default one has to be tested (inside of the loop only changed
    // options are tested)
    if (!dirExists(_options.at("root"))) {
        Error("Invalid root");
        return;
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
    _address.sin_addr.s_addr = inet_addr(_options["address"].c_str());
    _address.sin_port = htons(std::stoi(_options["port"]));

    memset(_address.sin_zero, '\0', sizeof(_address.sin_zero));

    const int trueFlag = 1;
    if (setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0) {
        Error("Error in setsockopt");
        return;
    }

    if (bind(_serverFd, (struct sockaddr *) &_address, sizeof(_address)) < 0) {
        Error("Error in bind");
        return;
    }
    if (listen(_serverFd, 10) < 0) {
        Error("Error in listen");
        _setupStatus = FAIL;
        return;
    }

    if (_locations[_options["logLocation"]] == FILE) { // consoleLogger is there by default
        if (!fileOk(_options["logFile"])) {
            Error("Cannot write to file");
            return;
        }
        _logger = std::make_unique<FileLogger>(_options["logFormat"], _options["logFile"]);
    }

    _setupStatus = OK;
}

void Server::ShutDown() {
    Log(ShutDownLog(false));
    _shutDown = true;
}

void Server::Log(const class Log &log) const {
    _logger->Log(log);
}

const std::string &Server::GetRoot() const {
    return _options.at("root");
}

int Server::Listen() {
    if (_setupStatus == SETUP_STATUS::FAIL) return SETUP_FAIL;


    // BUG - tests from browser are not beeing listed well
    // if you send test from browser, server doesn't hear it and responds late
    // normally is test response send after another request is recieved
    // NOTE - if test requested from iPad, it is responded at once

    // NOTE - I have no idea how to solve, maybe refresh of that listening loop every 0.1 second could help? But I'm not sure
    // I'm ready to simply accept it as a bug of chrome


    Controller controller(this, std::stoi(_options["maxThreads"]), std::stoi(_options["maxQueue"]));
    while (true) {
        // BUG - shutting down doesn't work optimally
        // NOTE - do I have to solve this? It seems like a quite acceptable bug to me, after shutdown's called
        // server only chills up to next request, doesn't hurt anyone, sounds ok to me
        if (_shutDown && _workersCount == 0) break;

        int newSocket;
        if ((newSocket = accept(_serverFd, (sockaddr *) &_address, (socklen_t *) &_addrLen)) < 0) {
            Error("Error in accept");
            return LISTEN_FAIL;
        }
        controller.Run(newSocket);
    }
    Log(ShutDownLog(true));
    return LISTEN_SUCCESS;
}

int Server::DecWorkers() { // increments worker counts and returns it
    return --_workersCount;
}

int Server::IncWorkers() { // increments worker counts and returns it
    return ++_workersCount;
}
