#include "responseLog.h"

std::string ResponseLog::ToString(const std::string &format) const {
    return Serialize(format);
}

void ResponseLog::SetCustom(const std::map<std::string, std::string> &data) {
    // saves everything
    for(const auto &l : data) {
        _customMessage.append(CreateLine(
                l.first + ": " + l.second
        ));
    }
}

std::string ResponseLog::Serialize(const std::string &format) const {
    std::string response = format;

    FindAndReplace(response,HEADER_NAME, HEADER);
    FindAndReplace(response,CUSTOM_NAME, _customMessage);

    AddCommonPart(response);

    return response;
}
