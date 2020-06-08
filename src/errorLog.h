#ifndef PA2_SERVER_ERRORLOG_H
#define PA2_SERVER_ERRORLOG_H

#include "log.h"

class ErrorLog : public Log {
public:
    ErrorLog(const std::string &message, bool fatal = true) : _fatal(fatal) {
        // ASK_0 - base mebers have to be initilazed like that?
        _customMessage = message;
    }

    std::string ToString(const std::string &format) const override {
        return Serialize(format);
    }


private:
    const char *ERROR_HEADER{"Error"};
    const char *WARNING_HEADER{"Warning"};
    bool _fatal{true};

    std::string Serialize(const std::string &format) const override {
        std::string response = format;

        FindAndReplace(response,HEADER_NAME, _fatal ? ERROR_HEADER : WARNING_HEADER);
        FindAndReplace(response,CUSTOM_NAME, _customMessage);

        AddCommonPart(response);
        return response;
    }
};


#endif //PA2_SERVER_ERRORLOG_H
