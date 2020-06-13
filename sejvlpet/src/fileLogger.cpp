#include "fileLogger.h"
#include <fstream>

FileLogger::FileLogger(const std::string &format, std::string fileName) : Logger(format), _fileName(std::move(fileName)) {}

void FileLogger::Log(const class Log &log) const {
    WriteOut(log.ToString(_format));
}

void FileLogger::WriteOut(const std::string &msg) const {
    std::lock_guard<std::mutex> guard(_fileMutex);

    std::ofstream f(_fileName, std::ios_base::app);
    f.write(msg.data(), msg.size());
}
