#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

template <typename T> class queueSafe {
  private:
    std::queue<T> _q;
    mutable std::mutex _mt;
    mutable std::condition_variable _cv;
    bool ready = false;

  public:
    queueSafe() = default;
    bool push(T);
    void pop();
    T getData();
};

template <typename T> bool queueSafe<T>::push(T t) {
    std::unique_lock<std::mutex> lk(this->_mt);
    _q.push(t);

    lk.unlock();
    _cv.notify_all();
    return true;
}

template <typename T> void queueSafe<T>::pop() {
    std::unique_lock<std::mutex> lk(this->_mt);
    _q.pop();
}

template <typename T> T queueSafe<T>::getData() {
    std::unique_lock<std::mutex> lk(this->_mt);

    _cv.wait(lk, [this]() { return !this->_q.empty(); });

    T ret = _q.back();
    _q.pop();

    return ret;
}

// Expect tgetData will wait until it's waked up by pushData thread
int main() {
    queueSafe<int> qs;
    std::thread tgetData([&qs]() {
        for (auto i = 0; i < 1002; i++)
            std::cout << "data << \n" << qs.getData() << "\n";
    });
    std::thread tpushData([&qs]() {
        for (auto i = 0; i < 1000; i++) {
            qs.push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });
    tgetData.join();
    tpushData.join();

    return 0;
}
