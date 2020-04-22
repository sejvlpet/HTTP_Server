#include <iostream>
#include "log.h"
#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H


class Logger {
public:
    // todo add logic and move to .cpp
    virtual void Log(const Log &log)  {
        std::cout << "Log from base class\n";
    }

    virtual Logger *Clone() {
        return new Logger(*this);
    }
};



class FileLogger : public Logger {
public:
    // fixme why there has to be keyword class?
    void Log(const class Log &log) override {
        std::cout << "Log from FileLogger class\n";
    }

    FileLogger *Clone() override {
        return new FileLogger(*this);
    }
};


class ConsoleLogger : public Logger {
public:
    // fixme why there has to be keyword class?
    void Log(const class Log &log) override {
        std::cout << "Log from ConsoleLogger class\n";
    }

    ConsoleLogger *Clone() override {
        return new ConsoleLogger(*this);
    }
};


#endif //PA2_SERVER_LOGGER_H
