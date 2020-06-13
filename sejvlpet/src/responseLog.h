#ifndef PA2_SERVER_RESPONSELOG_H
#define PA2_SERVER_RESPONSELOG_H

#include <map>
#include "log.h"

class ResponseLog : public Log {
public:
    /**
     * @copydoc Log::ToString()
     */
    std::string ToString(const std::string &format) const override;

    /**
     * saves data from custom message
     * @param data to save from
     */
    void SetCustom(const std::map<std::string, std::string> &data);

private:
    const char *HEADER{"Reponse Log"}; //<! header

    /**
     * @copydoc Log::Serialize()
     */
    std::string Serialize(const std::string &format) const override;

};


#endif //PA2_SERVER_RESPONSELOG_H
