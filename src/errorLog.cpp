#include "errorLog.h"

ErrorLog::ErrorLog(const std::string &message, bool fatal) : _fatal(fatal) {
    _customMessage = message;
}

std::string ErrorLog::ToString(const std::string &format) const {
    return Serialize(format);
}

std::string ErrorLog::Serialize(const std::string &format) const {
    std::string response = format;

    FindAndReplace(response,HEADER_NAME, _fatal ? ERROR_HEADER : WARNING_HEADER);
    FindAndReplace(response,CUSTOM_NAME, _customMessage);

    AddCommonPart(response);
    return response;
}
