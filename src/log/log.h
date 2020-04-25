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
    virtual std::string ToString() const = 0;

protected:
    std::chrono::time_point<std::chrono::system_clock> _dateTime;
    const char *HEADER{"Base Log"};
    const char *SEPARATOR{"----------------------\n"};

    virtual std::string Serialize() const {
        std::string response;
        response.append(HEADER);
        response.push_back('\n');
        response.append(TimeToString());
        response.push_back('\n');
        AddSeparators(response);
        return response;
    }

    std::string TimeToString() const {
        std::time_t t = std::chrono::system_clock::to_time_t(_dateTime);
        std::string ts = std::ctime(&t);
        ts.resize(ts.size() - 1);
        return ts;
    }

    void AddSeparators(std::string &response) const {
        // insert here is quite innefective, but readability is better and response shouldn't be long
        response.insert(0, SEPARATOR);
        response.append(SEPARATOR);
    }
};


#endif //PA2_SERVER_LOG_H
