#include <iostream>
#include "consoleLogger.h"

ConsoleLogger::ConsoleLogger(const std::string &format) : Logger(format) {}

void ConsoleLogger::Log(const class Log &log) const {
    WriteOut(log.ToString(_format));
}

void ConsoleLogger::WriteOut(const std::string &msg) const {
    std::lock_guard<std::mutex> guard(_consMutex);
    std::cout << msg;
}
