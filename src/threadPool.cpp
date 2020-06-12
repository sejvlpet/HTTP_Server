#include "threadPool.h"

ThreadPool::ThreadPool(size_t numThreads) {
    Setup(numThreads);
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock{_eventMutex};
        _stopping = true;
    }

    _eventVar.notify_all();

    for (auto &thread : _threads)
        thread.join();
}

size_t ThreadPool::GetCountOfQueued() const {
    return _tasks.size();
}

void ThreadPool::Setup(size_t numThreads) {
    for (size_t i = 0; i < numThreads; ++i) {
        _threads.emplace_back([=] {
            while (true) {
                Task task;

                {
                    // we take task from queue in its own scope so mutex can be locked as little as possible
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
