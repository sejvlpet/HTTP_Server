#include "requestLog.h"

std::string RequestLog::ToString(const std::string &format) const {
    return Serialize(format);
}

void RequestLog::SetCustom(const std::map<std::string, std::string> &data) {
    try {
        if (data.at("valid") == "false") {
            _customMessage.append(CreateLine("This request was invalid"));
            return;
        }
    } catch (...) {
        _customMessage.append(CreateLine(
                _customMessage.append(CreateLine("This request was invalid"))
        ));
        return;
    }
    for (const std::string &l : _toLog) {
        try {
            _customMessage.append(CreateLine(
                    l + ": " + data.at(l)
            ));
        } catch (...) {
            _customMessage.append(CreateLine(
                    l + ":"
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
