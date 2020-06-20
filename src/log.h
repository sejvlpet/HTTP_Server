#ifndef PA2_SERVER_LOG_H
#define PA2_SERVER_LOG_H

#include <chrono>
#include <string>

/**
 * Virtual base class for Logs
 */
class Log {
public:
    /**
     * saves time of log creation
     */
    Log();

    /**
     * serializes itself to string and returns it
     * @param format specifies how to serialize
     * @return formated string
     */
    virtual std::string ToString(const std::string &format) const = 0;
    virtual ~Log()= default;

protected:
    std::chrono::time_point<std::chrono::system_clock> _dateTime; //<! time of log creation
    const char *SEPARATOR{"----------------------"}; //<! to seperate logs
    const char *HEADER_NAME{"$HEADER$"}; //<! code for header in string format
    const char *CUSTOM_NAME{"$CUSTOM$"}; //<! code for customs in string fomrat

    std::string _customMessage; //<! custom message for logs

    /**
     * @copydoc Log::ToString(
     */
    virtual std::string Serialize(const std::string &format) const = 0;

    /**
     * wraps data with newline
     * @param data Data top be wrapped
     * @return data with appened newline
     */
    std::string CreateLine(const std::string &data) const;

    /**
     * Children have some common parts, here are being apped to response
     * @param response response where common parts shall be append
     */
    void AddCommonPart(std::string &response) const;

    /**
     * Places real values (value) instead of code (key) in format string (message)
     * @param message container where replacement shall happen
     * @param key Value in message to be replaced by parameter value
     * @param value Value to be placed instead of key
     */
    void FindAndReplace(std::string &message, const std::string &key, const std::string &value) const;



private:
    const char *NEWLINE_NAME{"$NEWLINE$"}; //<! code for newline in format
    const char *TIME_NAME{"$TIME$"}; //<! code for time in format
    const char *SEPARATOR_NAME{"$SEPERATOR$"}; //<! code for separator in format
    const char *NEWLINE{"\n"}; //<! new line string

    /**
     * creates string from time object
     * @return time as string
     */
    std::string TimeToString() const;

    /**
     * iterates over message and places NEWLINE instead of NEWLINE_NAME
     * @param message
     */
    void ReplaceNewLines(std::string &message) const;

};


#endif //PA2_SERVER_LOG_H
