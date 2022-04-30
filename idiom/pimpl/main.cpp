#include <iostream>
#include "lib.h"

int main(int argc, char *argv[]) {

    Widget(a);

    auto psa = std::move(a);
    auto psb = std::move(psa);

    return 0;
}
