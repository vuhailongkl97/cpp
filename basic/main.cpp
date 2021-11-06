#include <bits/stdc++.h>

using namespace std;

class test{
    public:
        explicit test(int _x):x(_x){
            cout << "constructor\n";
        }

        explicit test(initializer_list<int>(a)){
            cout << "ffconstructor\n";
        }
        ~test(){
            cout << "destructor\n";
        }
    private:
        int x;
};

void show(test &x)
{

}

void show(shared_ptr<test> pt)
{

}

int main()
{
    test *x = new test(1);
    show(shared_ptr<test>(x));
    delete x;

    return 0;
}
