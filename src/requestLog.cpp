#include "requestLog.h"

std::string RequestLog::ToString(const std::string &format) const {
    return Serialize(format);
}

void RequestLog::SetCustom(std::map<std::string, std::string> &data) {
    if (data["valid"] == "false") _customMessage.append(CreateLine("This request was invalid"));
    else {
        for (const std::string &l : _toLog) {
            _customMessage.append(CreateLine(
                    l + ": " + data[l]
            ));
        }
    }
}

std::string RequestLog::Serialize(const std::string &format) const {
    std::string response = format;

    FindAndReplace(response, HEADER_NAME, HEADER);
    FindAndReplace(response, CUSTOM_NAME, _customMessage);

    AddCommonPart(response);

    return response;
}
