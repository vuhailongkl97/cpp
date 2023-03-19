#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream> // std::ifstream
#include <future>
#include <iostream> // std::cerr
#include <thread>

using namespace std::literals::chrono_literals;
using namespace std::chrono;
template <typename T> class StopWatch {
  public:
    StopWatch(T &result) : _result{result} {
        _start = high_resolution_clock::now();
    }
    ~StopWatch() {
        _result = duration_cast<T>(high_resolution_clock::now() - _start);
        std::cout << _result.count() << "\n";
    }

  private:
    T &_result;
    time_point<high_resolution_clock> _start;
};
