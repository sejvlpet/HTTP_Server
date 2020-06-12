#ifndef PA2_SERVER_THREADPOOL_H
#define PA2_SERVER_THREADPOOL_H


#include <condition_variable>
#include <functional>
#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <queue>
#include "worker.h"

/**
 * inspired by https://www.youtube.com/watch?v=eWTGtp3HXiw
 * Thread pool with queue acceptes task and then executes them in seperate thread which are recyclatd
 */
class ThreadPool {
public:
    using Task = std::function<void()>;

    /**
     * Calls setup with given numThreads
     * @param numThreads count of threads to be used
     */
    ThreadPool(size_t numThreads);

    /**
     * Stops and joins threads
     */
    ~ThreadPool();

    /**
     * Method to accept and add worker to queue
     * @tparam T templated type to be stored in queue
     * @param worker object to be stored in queue
     */
template<class T>
    void Enqueue(T worker) {
        // todo find out what the hell is that
        auto wrapper = std::make_shared<std::packaged_task<decltype(worker())()>>(std::move(worker));
        {
            // we take task from queue in its own scope so mutex can be locked as little as possible
            std::unique_lock<std::mutex> lock{_eventMutex};
            _tasks.emplace([=] {
                (*wrapper)();
            });
        }

        _eventVar.notify_one();
    }
    /**
     * @return count of object in queue
     */
    size_t GetCountOfQueued() const;

private:
    std::vector<std::thread> _threads; //<! vector of thread
    std::condition_variable _eventVar; // fixme I have no idea what does this thing do
    std::mutex _eventMutex; //<! mutex for thread safety
    bool _stopping = false; //<! set to true if thread pool should stop

    std::queue<Task> _tasks; //<! queue of tasks

    /**
     * Fills vector of threads, in each threads runs lambda fucntion which waits for signal (to end or work);
     * @param numThreads count of threads
     */
    void Setup(size_t numThreads);
};


#endif //PA2_SERVER_THREADPOOL_H


