#include <iostream>
#include <bits/unique_ptr.h>
#include "../log/log.h"
#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H


class Logger {
public:
    // todo add logic and move to .cpp
    virtual void Log(const std::unique_ptr<class Log> &log) const = 0;
    virtual void Log(const class Log &log) const = 0;

};


#endif //PA2_SERVER_LOGGER_H
