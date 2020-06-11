#ifndef PA2_SERVER_LOG_H
#define PA2_SERVER_LOG_H

#include <chrono>
#include <string>

class Log {
public:
    Log();

    virtual std::string ToString(const std::string &format) const = 0;
    virtual ~Log()= default;

protected:
    std::chrono::time_point<std::chrono::system_clock> _dateTime;
    const char *SEPARATOR{"----------------------"};
    const char *HEADER_NAME{"$HEADER$"};
    const char *CUSTOM_NAME{"$CUSTOM$"};

    std::string _customMessage;

    virtual std::string Serialize(const std::string &format) const = 0;

    std::string CreateLine(const std::string &data) const;

    void AddCommonPart(std::string &response) const;


    void FindAndReplace(std::string &message, const std::string &key, const std::string &value) const;



private:
    const char *NEWLINE_NAME{"$NEWLINE$"};
    const char *TIME_NAME{"$TIME$"};
    const char *SEPARATOR_NAME{"$SEPERATOR$"};
    const char *NEW_LINE{"\n"};

    std::string TimeToString() const;

    void ReplaceNewLines(std::string &message) const;

};


#endif //PA2_SERVER_LOG_H
