#ifndef PA2_SERVER_LOG_H
#define PA2_SERVER_LOG_H

#include <ctime>
#include <chrono>
#include <string>
#include <iostream>
#include <cstring>


class Log {
public:
    Log() {
        _dateTime = std::chrono::system_clock::now();
        ++_id;
    }

    virtual std::string ToString(const std::string &format) const = 0;
    virtual ~Log()= default;

protected:
    std::chrono::time_point<std::chrono::system_clock> _dateTime;
    const char *SEPARATOR{"----------------------"};
    const char *HEADER_NAME{"$HEADER$"};
    const char *CUSTOM_NAME{"$CUSTOM$"};

    std::string _customMessage;
    static size_t _id;

    virtual std::string Serialize(const std::string &format) const = 0;

    std::string CreateLine(const std::string &data) const {
        return data + '\n';
    }

    void AddCommonPart(std::string &response) const {
        FindAndReplace(response,TIME_NAME, TimeToString());
        FindAndReplace(response,ID_NAME, std::to_string(_id));

        ReplaceNewLines(response);
        FindAndReplace(response, SEPARATOR_NAME, CreateLine(SEPARATOR));
    }


    void FindAndReplace(std::string &message, const std::string &key, const std::string &value) const {
        size_t index = message.find(key);
        if (index != std::string::npos) {
            message.replace(index, key.length(), value);
        }
    }



private:
    const char *NEWLINE_NAME{"$NEWLINE$"};
    const char *ID_NAME{"$ID$"};
    const char *TIME_NAME{"$TIME$"};
    const char *SEPARATOR_NAME{"$SEPERATOR$"};
    // ASK_1 - not sure if is this good choice, new_line could also be just char
    const char *NEW_LINE{"\n"};

    std::string TimeToString() const {
        std::time_t t = std::chrono::system_clock::to_time_t(_dateTime);
        std::string ts = std::ctime(&t);
        ts.resize(ts.size() - 1);
        return ts;
    }

    void ReplaceNewLines(std::string &message) const {
        std::string::size_type start = 0;

        // finds next occurence of newline
        while ((start = message.find(NEWLINE_NAME, start)) != std::string::npos) {
            message.replace(start, strlen(NEWLINE_NAME), NEW_LINE);
            start += 1;
        }
    }

};


#endif //PA2_SERVER_LOG_H
