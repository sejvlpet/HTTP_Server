#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H

#include <map>
#include "requestLog.h"
#include "server.h"

class Request {
public:
    // returns log object about request parsing
    Log &GetLog();

    // from parsed request setups request
    void Setup(std::map<std::string, std::string> &parsed, int socket);

    int GetSocket() const;

    bool IsValid() const;

    const std::string &GetTarget() const;

    const std::string &GetExtension() const;

    const std::string &GetRoot() const;
private:
    // BUG - sometimes server sends default response - something went wrong with code 500 to itself
    // I'm quite sure that it is because of this default set of _socket to zero - how should I solve it?
    // ASK_1 - should I problem described above solve by not sending anything to socket with number 0, let it be,
    // or somehow else?

    // NOTE I'll ignore that, it doesn't happen that often

    // NOTE 2 - bug happens only in some explorers, I won't try solve it
    int _socket{0};
    std::map<std::string, std::string> _params;
    RequestLog _log;
    static size_t _id;

    void CreateLog();
};


#endif //PA2_SERVER_REQUEST_H
