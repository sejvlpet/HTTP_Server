#ifndef PA2_SERVER_FILELOGGER_H
#define PA2_SERVER_FILELOGGER_H

#include <utility>
#include <fstream>

#include "logger.h"

class FileLogger : public Logger {
public:
    FileLogger(const std::string &format, std::string fileName) : Logger(format), _fileName(std::move(fileName)) {}
    // fixme why there has to be keyword class?
    void Log(const std::unique_ptr<class Log> &log) const override {
        std::string tmp = log->ToString(_format);
        std::ofstream f(_fileName, std::ios_base::app);
        f.write(tmp.data(), tmp.size());
    }
    void Log(const class Log &log) const override {
        std::string tmp = log.ToString(_format);
        std::ofstream f(_fileName, std::ios_base::app);
        f.write(tmp.data(), tmp.size());
    }

private:
    std::string _fileName;
};


#endif //PA2_SERVER_FILELOGGER_H
