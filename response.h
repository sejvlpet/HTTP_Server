#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include <bits/unique_ptr.h>
#include "log.h"

class Response {
public:
    std::unique_ptr<Log> GetLog(){
        ResponseLog tmp;
        return std::make_unique<ResponseLog>(tmp);
    }
};


#endif //PA2_SERVER_RESPONSE_H
