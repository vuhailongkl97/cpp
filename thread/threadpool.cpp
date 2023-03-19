#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// https://stackoverflow.com/questions/9094422/how-to-check-if-a-stdthread-is-still-running
class ThreadPool {
  private:
    size_t maxThreads = 0;
    bool terminate = false;
    std::condition_variable m_cv;
    std::mutex m_lock;
    std::vector<std::future<bool>> mv_pool;

  public:
    ThreadPool(int size) : maxThreads(size) {}

    template <typename CallAble, typename... T>
    bool enqueue(CallAble &fun, T &&...args) {
        std::unique_lock<std::mutex> l(m_lock);
        m_cv.wait(l, [this]() {
			std::cout << "waiting\n";
            return (!terminate && (mv_pool.size() <= maxThreads));
        });

        mv_pool.push_back(
            std::async(std::launch::async, fun, std::forward<T>(args)...));

        return true;
    }

    std::future<void> loop() {
        // wait to delete task , update available thread
        return std::async(std::launch::async, [&]() {
            while (!terminate) {
                for (auto i = mv_pool.begin(); i != mv_pool.end(); i++) {
                    auto status = i->wait_for(std::chrono::microseconds(0));
                    if (status == std::future_status::ready) {
                        mv_pool.erase(i);
                        m_cv.notify_one();
                        break;
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
        });
    }
    void stop() {
        terminate = true;
        m_cv.notify_all();
        for (auto &i : mv_pool)
            i.wait();
    }
};

bool th1(int &i) {
    auto tmp = i;
    std::this_thread::sleep_for(std::chrono::milliseconds(i*4000));
    i *= 2;
	std::cout << "done " << i << "\n";
    return true;
}
int main() {
    ThreadPool p(1);
    auto f1 = p.loop();
    int i = 1;
    p.enqueue(th1, std::ref(i));
    p.enqueue(th1, std::ref(i));
    p.enqueue(th1, std::ref(i));
    p.enqueue(th1, std::ref(i));

    p.stop();

    std::cout << i << "\n";
    return 0;
}
