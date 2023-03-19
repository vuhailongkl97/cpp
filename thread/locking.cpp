#include "stopWatch.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
mutex t1;
mutex t2;
long long shared_value = 1000000;
// test deadlock
//  make 2 difference thread keep each lock -> one wait other -> deadlock
void deadLockWorker(mutex &t1, mutex &t2) {
    t1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    t2.lock();
    while (shared_value > 0)
        shared_value--;
    t1.unlock();
    t2.unlock();
}
void deadlock_test() {
    shared_value = 1000000;
    std::thread th1(deadLockWorker, std::ref(t1), std::ref(t2));
    std::thread th2(deadLockWorker, std::ref(t2), std::ref(t1));

    th1.join();
    th2.join();
    cout << __func__ << "shared_value " << shared_value << " DONE\n";
}
void antiDeadlockWorker(mutex &t1, mutex &t2) {
    std::scoped_lock sl(t1, t2);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    while (shared_value > 0)
        shared_value--;
}
void antiDeadLock_test() {
    shared_value = 1000000;
    microseconds result;
    StopWatch<microseconds> sw(result);
    std::thread th1(antiDeadlockWorker, std::ref(t1), std::ref(t2));
    std::thread th2(antiDeadlockWorker, std::ref(t2), std::ref(t1));
    th1.join();
    th2.join();
    cout << __func__ << "shared_value " << shared_value << " DONE\n";
}

void livelockWorker(mutex &t1, mutex &t2) {

    cout << __func__ << "\n";
    while (shared_value > 0) {
        t1.lock();
        if (!t2.try_lock()) {
            t1.unlock();
            std::this_thread::yield();
            continue;
        } else {
            shared_value--;
            t1.unlock();
            t2.unlock();
        }
    }
}

void livelock_test() {
    shared_value = 1000000;
    microseconds result;
    StopWatch sw(result);
    std::thread th1(livelockWorker, std::ref(t1), std::ref(t2));
    std::thread th2(livelockWorker, std::ref(t2), std::ref(t1));
    th1.join();
    th2.join();
    cout << __func__ << "shared_value " << shared_value << " DONE\n";
}
int main() {
    std::cout << __cplusplus << "\n";
    std::this_thread::get_id();
    (void)std::stoi("12");
    deadlock_test();
    // deadlock_test();
    antiDeadLock_test();
	livelock_test();
    livelock_test();
    return 0;
}
