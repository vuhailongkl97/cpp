## std::move, std::forward and note

noexcept, 
__attribute__((inline)), inline (compiler do parser, check) over macro
throw std::logic_error
ON_CALL(mock, method)
    .WillByDefault(Return(value));

has a (Object Composition)
is a (Implementation Inheritance)

pointer reseat but reference can't
API Design for C++
std::forwarding for auto && var
auto && can bind to anything but auto & can't. incase of parameter is lvalue

void show(auto &&x)
{
    // now x is lvalue,
    std::move alway cast to rvalue
    std::forward don't cast, it will forward what caller pass parameter to it in template

}
template <typename T>
void show_with_r(T &a)
{
    show2(a);// pass lvalue to show2
    show2(std::move(a));// pass rvalue to show2
}

template <typename T>
void show_with_rr(T &&a)
{
    show2(a);// pass lvalue to show2
    show2(std::move(a));// pass rvalue to show2
}

template <typename T>
void show_for_all(T &&a)
{
    show2(std::forward<T>(a));
}

=> base on what caller pass "a" parameter to function, compiler will pass it show2 correctly
show_for_all(a); -> pass a as lvalue to show2
show_for_all(std::move(a)); -> pass a as rvalue to show2

