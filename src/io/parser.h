#ifndef PA2_SERVER_PARSER_H
#define PA2_SERVER_PARSER_H
#include "request.h"

class Parser {
public:
    // reads buffer, saves information from which it creates its parsed request which shall be later returned
    Parser(const char *buffer) {

    }

    Request GetRequest(int socket) {
        Request tmp(socket);
        return tmp;
    }

private:
    Request _parsedRequest;
};


#endif //PA2_SERVER_PARSER_H
