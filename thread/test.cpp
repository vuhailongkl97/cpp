// ios::exceptions
#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>  // std::ifstream
#include <future>
#include <iostream>  // std::cerr
#include <optional>
#include <queue>
#include <thread>
#include <condition_variable>

template <typename T>
class thread_safe_queue {
    public:
    std::optional<T> top() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_queue.empty()) {
            return std::optional<T>(_queue.top());
        } else {
            return std::nullopt;
        }
    }
    void pop()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_queue.empty()) {
            _queue.pop();
        } else {
        }
    }
    void wait_and_pop()
    {
        std::unique_lock ul{_mutex};
        _cv.wait(ul, [&](){
            return _queue.size() != 0;
        });

        _queue.pop();
    }
    void push(const T &a) {
        std::cout << "a\n";
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(a);
        _cv.notify_all();
    }

    size_t size()
    {
        return _queue.size();
    }

   private:
    std::condition_variable _cv;
    static std::mutex _mutex;
    std::queue<T> _queue;
};

template <typename T>
std::mutex thread_safe_queue<T>::_mutex;

int main() {
    using namespace std::literals::chrono_literals;
    using namespace std::chrono;
    int num = 1000;
    thread_safe_queue<int> tsq;

    std::future tsq1 = std::async(std::launch::async, [&](){
        for(auto i = 0; i< num; i++)
        {
            tsq.push(i);
        }
    });

    std::future tsq2 = std::async(std::launch::async, [&](){
        for(auto i = 0; i< num; i++)
        {
            tsq.wait_and_pop();
        }
    });
    tsq1.wait();
    tsq2.wait();

    // std::this_thread::sleep_for(1000ms);
    std::cout << tsq.size() << "\n";



    return 0;
}
