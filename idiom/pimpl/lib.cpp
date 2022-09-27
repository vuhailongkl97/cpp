#include "lib.h"
#include <iostream>

using namespace std;

struct Widget::Pimpl {
    int a;
    float b;
};

struct deleter {

    void operator()(Widget::Pimpl *w) {
        std::cout << "deleter here \n";
        delete w;
    }
};

Widget::Widget()
    : pimpl(std::shared_ptr<Widget::Pimpl>(new Widget::Pimpl(), deleter())) {
    std::cout << "constructor \n";
}

Widget::Widget(Widget &&o) { std::cout << "move constructor \n"; }

Widget::Widget(const Widget &o) { std::cout << "copy constructor \n"; }
