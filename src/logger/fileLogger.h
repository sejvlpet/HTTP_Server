#ifndef PA2_SERVER_FILELOGGER_H
#define PA2_SERVER_FILELOGGER_H

#include <utility>
#include <fstream>
#include <mutex>
#include <unistd.h>


#include "logger.h"

/**
 * Writes logs to file given in configuration, thread safe
 */
class FileLogger : public Logger {
public:
    FileLogger(const std::string &format, std::string fileName) : Logger(format), _fileName(std::move(fileName)) {}
    // fixme why there has to be keyword class?
    void Log(const std::unique_ptr<class Log> &log) const override {
        WriteOut(log->ToString(_format));
    }
    void Log(const class Log &log) const override {
        WriteOut(log.ToString(_format));
    }

private:
    std::string _fileName;
    mutable std::mutex _fileMutex;


    void WriteOut(const std::string &msg) const {
        std::lock_guard<std::mutex> guard(_fileMutex);

        std::ofstream f(_fileName, std::ios_base::app);
        f.write(msg.data(), msg.size());
    }
};


#endif //PA2_SERVER_FILELOGGER_H
