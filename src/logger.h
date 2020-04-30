#include <iostream>
#include <utility>
#include <bits/unique_ptr.h>
#include "log.h"

#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H


class Logger {
public:
    Logger(std::string format) : _format(std::move(format)) {}
    // todo add logic and move to .cpp
    virtual void Log(const std::unique_ptr<class Log> &log) const = 0;

    virtual void Log(const class Log &log) const = 0;

    virtual ~Logger()=default;

protected:
    std::string _format;
};


#endif //PA2_SERVER_LOGGER_H
