#ifndef PA2_SERVER_PARSER_H
#define PA2_SERVER_PARSER_H
#include "request.h"

/**
 * Reads socket content and parses it to something better
 */
class Parser {
public:
    /**
     * accepts parametr and parses request on given socket
     * @param buffer Requst is stored there as string
     * @param socket Socket number
     * @param root Directory name
     */
    Parser(const char *buffer, int socket, std::string root);
   /**
    * @return moves parsed request
    */
    Request GetRequest();


private:
    Request _parsedRequest; //<! request is stored there after parsing
    std::map<std::string, std::string> _parsed; //<! key:value map of options from string request
    const std::string _buffer; //<! string request
    int _socket; //<! socket number
    const std::string _root; //<! dir name

    /**
     * Starts parsing
     */
    void Parse();

    /**
     * Sets targer - path in request
     */
    void SetTarget();

    /**
     * get extension of targer
     */
    void GetExtension();

    /**
     * From string request sets key:value map
     */
    void SetKeyValues();
};


#endif //PA2_SERVER_PARSER_H
