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

    void Run(int socket);

private:
    Server *_parent{nullptr};
    char _buffer[BUFFER_READ_SIZE]{0};
    ThreadPool _threadPool;
    size_t _maxQueue;


    // Parse message and saves it as request object
    Request ParseMessage(int socket);
};


#endif //PA2_SERVER_CONTROLLER_H
