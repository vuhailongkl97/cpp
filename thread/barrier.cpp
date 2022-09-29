#include <barrier>
#include <iostream>
#include <thread>

// barrier to make threads wait each other until barrier is full.
//
//
std::barrier t(10, []() { std::cout << "complete \n"; });
int i = 0;
void doPlus() {
    i += 1;
    std::cout << "Plus\n";
    (void)t.arrive();
}

void doMultiple() {
    t.arrive_and_wait();
    std::cout << "Mul\n";
    i *= 2;
}

int main() {

    std::thread pools[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2)
            pools[i] = std::thread(doPlus);
        else
            pools[i] = std::thread(doMultiple);
    }

    for (auto i = 0; i < 10; i++)
        pools[i].join();
    std::cout << "done " << i << " expect " << 5 * 32 << "\n";

    return 0;
}
