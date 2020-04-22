#ifndef PA2_SERVER_PARSER_H
#define PA2_SERVER_PARSER_H
#include "request.h"

class Parser {
public:
    Parser(const char *buffer) {

    }

    Request GetRequest(int socket) {
        Request tmp(socket);
        return tmp;
    }
};


#endif //PA2_SERVER_PARSER_H
