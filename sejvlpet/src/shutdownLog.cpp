#include "shutdownLog.h"

ShutDownLog::ShutDownLog(bool final) : _final(final) {}

std::string ShutDownLog::ToString(const std::string &format) const {
    return Serialize(format);
}

std::string ShutDownLog::Serialize(const std::string &format) const {
    std::string response = format;

    FindAndReplace(response,HEADER_NAME, _final ? HEADER_FINAL : HEADER_NOT_FINAL);
    FindAndReplace(response,CUSTOM_NAME, _customMessage);

    AddCommonPart(response);
    return response;
}
