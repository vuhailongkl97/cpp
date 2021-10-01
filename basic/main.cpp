#include <iostream>
#include <vector>
#include <array>
#include <list>

class test{
    public:
       test() = default;
       static constexpr int x = 10;
       int v = 1;
       void show(int a = x);
};

void test::show(int a)
{
    std::cout << a << std::endl;
}

int main(void)
{
    std::list<int> a;
    a.assign({1,2,3,4});

    for (std::list<int>::iterator it =a.begin(); it !=a.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
