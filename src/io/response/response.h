#ifndef PA2_SERVER_RESPONSE_H
#define PA2_SERVER_RESPONSE_H

#include <bits/unique_ptr.h>
#include "../../log/responseLog.h"

class Response {
public:
    // todo - hopefully unique_ptr returned like this'll thread safe (it really should), if no use shared_ptr
    std::unique_ptr<Log> GetLog(){
        // todo send not tmp but _log
        ResponseLog tmp;
        return std::make_unique<ResponseLog>(tmp);
    }
    virtual void WriteOut(int socket) {
        // fixme make abstract
    };

protected:
    ResponseLog _log;
    virtual void CreateLog() {
        // fixme make abstract
    };
};


#endif //PA2_SERVER_RESPONSE_H
