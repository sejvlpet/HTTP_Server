//
// Created by petrsejvl on 09.06.20.
//

#ifndef PA2_SERVER_THREADPOOL_H
#define PA2_SERVER_THREADPOOL_H


#include <condition_variable>
#include <functional>
#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <queue>
#include "request.h"
#include "worker.h"

// inspired by https://www.youtube.com/watch?v=eWTGtp3HXiw
class ThreadPool {
public:
    using Task = std::function<void()>;

    explicit ThreadPool(std::size_t numThreads) {
        Setup(numThreads);
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock{_eventMutex};
            _stopping = true;
        }

        _eventVar.notify_all();

        for (auto &thread : _threads)
            thread.join();
    }

    template<class T>
    void enqueue(T worker) {
        // todo find out what the hell is that
        auto wrapper = std::make_shared<std::packaged_task<decltype(worker())()>>(std::move(worker));
        {
            // fixme - is this really needed? It'd make sense only if notify_one would be expensive
            std::unique_lock<std::mutex> lock{_eventMutex};
            _tasks.emplace([=] {
                (*wrapper)();
            });
        }

        _eventVar.notify_one();
    }

    size_t GetCountOfQueued() const {
        return _tasks.size();
    }

private:
    std::vector<std::thread> _threads;
    std::condition_variable _eventVar; // fixme I have no idea what does this thing do
    std::mutex _eventMutex;
    bool _stopping = false;

    std::queue<Task> _tasks;


    void Setup(size_t numThreads) {
        for (size_t i = 0; i < numThreads; ++i) {
            _threads.emplace_back([=] {
                while (true) {
                    Task task;

                    {
                        // todo write some senseful comment about reason for this scope
                        std::unique_lock<std::mutex> lock{_eventMutex};

                        _eventVar.wait(lock, [=] { return _stopping || !_tasks.empty(); });

                        if (_stopping && _tasks.empty())
                            break;

                        task = std::move(_tasks.front());
                        _tasks.pop();
                    }
                    task();
                }
            });
        }
    }
};


#endif //PA2_SERVER_THREADPOOL_H
