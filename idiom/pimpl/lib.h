#pragma once
#include <memory>

class Widget{

    public:
        Widget();
        Widget (Widget && o);
        Widget (const Widget & o);
        struct Pimpl;
    private:
        std::shared_ptr<Pimpl> pimpl;
};
