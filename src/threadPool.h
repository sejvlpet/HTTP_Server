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

// inspired by https://www.youtube.com/watch?v=eWTGtp3HXiw
class ThreadPool {
public:
    using Task = std::function<void()>;

    explicit ThreadPool(size_t numThreads);

    ~ThreadPool();

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
    size_t GetCountOfQueued() const;

private:
    std::vector<std::thread> _threads;
    std::condition_variable _eventVar; // fixme I have no idea what does this thing do
    std::mutex _eventMutex;
    bool _stopping = false;

    std::queue<Task> _tasks;

    void Setup(size_t numThreads);
};


#endif //PA2_SERVER_THREADPOOL_H


