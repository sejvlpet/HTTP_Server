#include <iostream>
#include <utility>
#include <bits/unique_ptr.h>
#include "log.h"

#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H


class Logger {
public:
    Logger(std::string format);

    virtual void Log(const class Log &log) const = 0;

    virtual ~Logger()=default;

protected:
    std::string _format;

    virtual void WriteOut(const std::string &msg) const = 0;
};


#endif //PA2_SERVER_LOGGER_H
