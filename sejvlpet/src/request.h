#ifndef PA2_SERVER_REQUEST_H
#define PA2_SERVER_REQUEST_H

#include "requestLog.h"

/**
 * Keeps informations and functionality of accpeted request
 */
class Request {
public:
    /**
     * @return Returns refernce to Log object
     */
    Log &GetLog();

    /**
     * Setups from itself from parameters
     * @param parsed key:value map of request
     * @param socket socket number
     */
    void Setup(std::map<std::string, std::string> &parsed, int socket);

    /**
     * @return socket number
     */
    int GetSocket() const;

    /**
     * @return true if request is valid, false otherwise
     */
    bool IsValid() const;

    /**
     * @return referecne to target
     */
    const std::string &GetTarget() const;

    /**
     * @return referecne to extension
     */
    const std::string &GetExtension() const;

    /**
     * @return referecne to root
     */
    const std::string &GetRoot() const;
private:

    int _socket{0}; //<! socket number
    std::map<std::string, std::string> _params; //<! request saved in map
    RequestLog _log; //<! log object
    static size_t _id; //<! id of request
    std::string _invalidKeyVal{""}; //<! if anyone tries to get value by invalid key from _params, this shall be returned instead

    void CreateLog();
};


#endif //PA2_SERVER_REQUEST_H
