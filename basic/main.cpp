#include <bits/stdc++.h>

using namespace std;

class ftest;
class test;

class ftest{
    private:
    friend class test;
    void show(const test *a)
    {
    }
};

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
        void kk(){
            ftest a;
            const test *x = nullptr;
            a.show(x);
        }
    private:
        int x;
};

void show(shared_ptr<test> pt, int x)
{
    cout << "usecount : " << pt.use_count() << endl;
}

void create_obj()
{
    cout << __func__ << endl;
}

void show(unique_ptr<test> o)
{

}

void show(initializer_list<int> ii)
{
    for(auto &a : ii)
    {
        cout << a << endl;
    }
}

int main()
{
    #if 0
    test *x = new test(10);
    shared_ptr<test> px(x, [](test *x)-> int{cout << "okk destroy"<< endl; return 1;});
    unique_ptr<test> v(new test(2));

    show(std::move(v));
    show(px, 2);
    //
        weak_ptr<int> a;
        {
            auto shPInt = make_shared<int>(12);
            a = shPInt;
        }

        assert(a.lock());
    #endif
    show({1,2,3,4});




    return 0;
}
