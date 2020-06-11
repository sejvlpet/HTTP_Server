#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H
#include "log.h"


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
