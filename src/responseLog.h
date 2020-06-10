#ifndef PA2_SERVER_RESPONSELOG_H
#define PA2_SERVER_RESPONSELOG_H

#include <map>
#include "log.h"

class ResponseLog : public Log {
public:
    std::string ToString(const std::string &format) const override;

    void SetCustom(const std::map<std::string, std::string> &data);

private:
    const char *HEADER{"Reponse Log"};

    std::string Serialize(const std::string &format) const override;

};


#endif //PA2_SERVER_RESPONSELOG_H
