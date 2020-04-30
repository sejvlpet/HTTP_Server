#ifndef PA2_SERVER_LOG_H
#define PA2_SERVER_LOG_H

#include <ctime>
#include <chrono>
#include <string>
#include <iostream>



class Log {
public:
    Log() {
        _dateTime = std::chrono::system_clock::now();
    }

    // todo this method should be abstracy
    virtual std::string ToString(const std::string &format) const = 0;
    virtual ~Log()= default;

protected:
    std::chrono::time_point<std::chrono::system_clock> _dateTime;
    const char *HEADER{"Base Log"};
    const char *SEPARATOR{"----------------------"};
    std::string _customMessage;

    virtual std::string Serialize(const std::string &format) const = 0;

    std::string CreateLine(const std::string &data) const {
        return data + '\n';
    }

    void AddCommonPart(std::string &response) const {
        response.append(CreateLine(TimeToString()));
        response.append(CreateLine(SEPARATOR));
    }

    std::string TimeToString() const {
        std::time_t t = std::chrono::system_clock::to_time_t(_dateTime);
        std::string ts = std::ctime(&t);
        ts.resize(ts.size() - 1);
        return ts;
    }
};


#endif //PA2_SERVER_LOG_H
