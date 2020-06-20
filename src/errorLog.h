#ifndef PA2_SERVER_ERRORLOG_H
#define PA2_SERVER_ERRORLOG_H

#include "log.h"

class ErrorLog : public Log {
public:
    /**
     * stores members
     * @param message Custom message
     * @param fatal indicates whether is error to be logged fatal or not
     */
    ErrorLog(const std::string &message, bool fatal = true);

    /**
     * @copydoc Log::ToString()
     */
    std::string ToString(const std::string &format) const override;


private:
    const char *ERROR_HEADER{"Error"}; //<! header for case of fatal error
    const char *WARNING_HEADER{"Warning"}; //<! header for case of non fatal error
    bool _fatal{true}; //<! indicates whether is error fatal or not

    /**
     * @copydoc Log::Serialize()
     */
    std::string Serialize(const std::string &format) const override;
};


#endif //PA2_SERVER_ERRORLOG_H
