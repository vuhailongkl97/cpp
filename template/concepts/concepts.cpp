#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
concept bool is_integer() {
    return requires(T a) {
        { a += 2 } -> int;
    }
    &&std::is_integral<T>::value;
}

template <typename T>
requires std::is_copy_assignable<T>::value T mean(T a) {
    static_assert(!std::is_array<T>(), "type is array");
    return a + 1;
}

template <typename T, size_t Length>
requires std::is_arithmetic<T>::value T mean_array(T (&arr)[Length]) {
    int ret = 0;
    for (auto &i : arr) {
        ret += i;
    }
    return ret / Length;
}

template <typename T, typename... args> T mean_array(args... arguments) {
    int ret = 0;
    for (auto &p : {arguments...}) {
        ret += p;
    }

    return ret;
}
template <class Arg> int process(Arg arg, int &someOtherData) {
    std::cout << arg << " -\n";
    return arg + 10;
}

template <class... Args> void doSomething(Args... args) {
    int someOtherData;
    int x[] = {(process(args, someOtherData))...};
    for (auto &i : x) {
        std::cout << i << " +\n";
    }
}

template <typename T> struct Bank {
    Bank() = default;
    void make_transfer(T &from, T &to, double amount) {
        from -= amount;
        to += amount;
    }
};

struct Account {
    Account() = delete;
    Account(long default_amount) : _amount(default_amount) {}
    Account &operator-=(double amount);
    Account &operator+=(double amount);
    void show_amount() { std::cout << "amount " << _amount << "\n"; }
    long _amount;
};

Account &Account::operator-=(double amount) {
    this->_amount -= amount;
    return *this;
}
Account &Account::operator+=(double amount) {
    this->_amount += amount;
    return *this;
}

int main() {
    int x = 123;
    int arr[] = {1, 2, 3, 4};
    // std::cout << mean_array(arr);
    // std::cout << mean_array<int>(1,2,3,5);
    //    doSomething(1,2,3,4,5,6);
    Bank<long> bank;

    long from, to;
    from = 100, to = 0;
    bank.make_transfer(from, to, 12);

    Bank<Account> ba;
    Account afrom{123};
    Account ato{45};
    ba.make_transfer(afrom, ato, 12);

    afrom.show_amount();
    ato.show_amount();

    return 0;
}
