#ifndef PA2_SERVER_LOGGER_H
#define PA2_SERVER_LOGGER_H
#include "log.h"

/**
 * Handles saving logs
 */
class Logger {
public:
    Logger(std::string format);

    /**
     * virtual method to save log
     * @param log Log object to be saves
     */
    virtual void Log(const class Log &log) const = 0;

    virtual ~Logger()=default;

protected:
    std::string _format; //<! format string to which will log be placed

    /**
     * virtual method to write log as string
     * @param msg
     */
    virtual void WriteOut(const std::string &msg) const = 0;
};


#endif //PA2_SERVER_LOGGER_H
