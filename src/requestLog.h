#ifndef PA2_SERVER_REQUESTLOG_H
#define PA2_SERVER_REQUESTLOG_H
#include <map>
#include <vector>
#include "log.h"

/**
 * Handles logs of request
 */
class RequestLog : public Log {
public:
    /**
     * @copydoc Log::ToString()
     */
    std::string ToString(const std::string &format) const override;

    /**
     * From maps sets custom log message
     * @param data key:value map with informations
     */
    void SetCustom(const std::map<std::string, std::string> &data);

private:
    std::vector<std::string> _toLog{"target", "Host", "User-Agent", "id"}; //<! things to be saved in custom message
    const char *HEADER{"Request Log"}; //<! header

    /**
     * @copydoc Log::Serialize()
     */
    std::string Serialize(const std::string &format) const override;
};


#endif //PA2_SERVER_REQUESTLOG_H
