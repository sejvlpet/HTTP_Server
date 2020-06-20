#ifndef PA2_SERVER_CONTROLLER_H
#define PA2_SERVER_CONTROLLER_H

#include "threadPool.h"
#include "errorLog.h"

/**
 * Reads request from socket and creates workers to threadpool
 */
class Controller {
public:
    static const size_t BUFFER_READ_SIZE{300000}; //<! size of buffer

    /**
     * saves parametrs as members
     * @param parent pointer to parent server
     * @param maxThreads count of threads
     * @param maxQueue max queue size
     */
    Controller(Server *parent, size_t maxThreads, size_t maxQueue);

    /**
     * Parses request and tries to place worker into threadPool
     * @param socket Socket number
     */
    void Run(int socket);

private:
    Server *_parent{nullptr}; //<! pointer to parent server
    char _buffer[BUFFER_READ_SIZE]{0}; //<! buffer to store request
    ThreadPool _threadPool; //<! thread pool, where wokers with aprsed request shall be placed
    size_t _maxQueue; //<! max size of queue of workers waiting to be processed


    /**
     * @param socket Socket number to read request from
     * @return pardsed request
     */
    Request ParseMessage(int socket);
};


#endif //PA2_SERVER_CONTROLLER_H
