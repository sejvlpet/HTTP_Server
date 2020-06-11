#ifndef PA2_SERVER_PARSER_H
#define PA2_SERVER_PARSER_H
#include "request.h"

class Parser {
public:
    // reads buffer, saves information from which it creates its parsed request which shall be later returned
    Parser(const char *buffer, int socket, std::string root);

    Request GetRequest();


private:
    Request _parsedRequest;
    std::map<std::string, std::string> _parsed;
    const std::string _buffer;
    int _socket;
    const std::string _root;

    void Parse();

    void SetTarget();

    void GetExtension();


    void SetKeyValues();
};


#endif //PA2_SERVER_PARSER_H
