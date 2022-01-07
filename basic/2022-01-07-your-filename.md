## clang-format, cpp20, poco json, cpp cast

static_cast for illustrate implicit conversion
dynamic_cast used for illustrate conversion between derived and base class
reinterpret_cast used for illustrate conversion between different type which is poined by a pointer

generic programming


class abc{
 public:
    abc(){
        std::cout << "constructor\n";
    }
    ~abc(){
        std::cout << "destructor\n";
    }
};

concepts in cpp is define how and what are need for a typename
example :
concept T is type which can copyable, assignable, + operator ,...

clang-format-diff 
clang-format


====

why json::array need dynamic allocate memory, have shared pointer but it haven't initialized yet
let's use pointer instead of Array Object

clang-format-diff.py is a great tool to format code
we can create reference to variable itself when it is initialized but this is undefined behavior
https://stackoverflow.com/questions/9820027/using-newly-declared-variable-in-initialization-int-x-x1