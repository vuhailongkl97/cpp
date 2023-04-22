#include <chrono>
#include <fstream>
#include <future>
#include <iostream>
#include <thread>

using std::chrono::milliseconds, std::chrono::seconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using namespace std::chrono_literals;
using tp = std::chrono::time_point<high_resolution_clock>;

template <typename T> class StopWatch {
  public:
    explicit StopWatch(T &result) : result_{result} {
        start_ = high_resolution_clock::now();
    }
    ~StopWatch() {
        result_ = duration_cast<T>(high_resolution_clock::now() - start_);
        std::cout << result_.count() << "\n";
    }

  private:
    T &result_;
    tp start_;
};

int main() {
    auto the_future = std::async(std::launch::deferred, [] {
        std::this_thread::sleep_for(1000ms);
        return "ok1";
    });

    {
        milliseconds result;
        StopWatch<milliseconds> ret(result);
        std::this_thread::sleep_for(10ms);
        std::cout << the_future.get() << "\n";
    }

    return 0;
}
