#include "log.h"

Log::Log() {
    _dateTime = std::chrono::system_clock::now();
}

std::string Log::CreateLine(const std::string &data) const {
    return data + '\n';
}

void Log::AddCommonPart(std::string &response) const {
    FindAndReplace(response,TIME_NAME, TimeToString());

    ReplaceNewLines(response);
    FindAndReplace(response, SEPARATOR_NAME, CreateLine(SEPARATOR));
}

void Log::FindAndReplace(std::string &message, const std::string &key, const std::string &value) const {
    size_t index = message.find(key);
    if (index != std::string::npos) {
        message.replace(index, key.length(), value);
    }
}

std::string Log::TimeToString() const {
    std::time_t t = std::chrono::system_clock::to_time_t(_dateTime);
    std::string ts = std::ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}

void Log::ReplaceNewLines(std::string &message) const {
    std::string::size_type start = 0;

    // finds next occurence of newline
    while ((start = message.find(NEWLINE_NAME, start)) != std::string::npos) {
        message.replace(start, strlen(NEWLINE_NAME), NEW_LINE);
        start += 1;
    }
}
