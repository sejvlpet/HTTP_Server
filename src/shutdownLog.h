#ifndef PA2_SERVER_SHUTDOWNLOG_H
#define PA2_SERVER_SHUTDOWNLOG_H

#include "log.h"

class ShutDownLog : public Log {
public:
    /**
     * @param final true if shutdown is final and not just requested
     */
    ShutDownLog(bool final);

    /**
     * @copydoc Log::ToString()
     */
    std::string ToString(const std::string &format) const override;


private:
    const char *HEADER_NOT_FINAL{"Shutdown called Log"}; //<! header if shutdown isn't final
    const char *HEADER_FINAL{"Shutdown final Log"}; //<! header if shutdown is final
    bool _final{false}; //<! indicates whether shoutdown is final or not

    /**
     * @copydoc Log::Serialize()
     */
    std::string Serialize(const std::string &format) const override;

};

#endif //PA2_SERVER_SHUTDOWNLOG_H
