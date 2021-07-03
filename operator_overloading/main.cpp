#include <iostream>

using namespace std;

class PhanSo{
   private:
    int tu;
    int mau;
   public:
    void show() { cout << this->tu << "/" << this->mau << endl; }
    PhanSo(int, int);
    PhanSo operator + (PhanSo const &o);
    PhanSo operator - (PhanSo const &o);
    friend PhanSo operator * (PhanSo const &a, PhanSo const &b);
    friend PhanSo operator *= (PhanSo &a, PhanSo const &b);
    friend PhanSo operator / (PhanSo const &a, PhanSo const &b);
};

PhanSo::PhanSo(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau ? mau : 1;
}

PhanSo PhanSo::operator+(PhanSo const &o)
{
    PhanSo ret(1,1);
    ret.tu = this->tu * o.mau + this->mau*o.tu;
    ret.mau = this->mau* o.mau;

    return ret;
}

PhanSo PhanSo::operator-(PhanSo const &o)
{
    PhanSo ret(o.tu*-1,o.mau);

    return (*this) + ret;
}


PhanSo operator * (PhanSo const &a, PhanSo const &b)
{
    PhanSo ret(1,1);
    ret.tu = a.tu*b.tu;
    ret.mau= a.mau*b.mau;

    return ret;
}

PhanSo operator / (PhanSo const &a, PhanSo const &b)
{
    PhanSo ret(b.mau, b.tu);

    return ret * a;
}

PhanSo operator *= (PhanSo &a, PhanSo const &b)
{
    a = a*b;
    return a;
}


int main(void)
{

    PhanSo a(1,2), b(3,4);
    PhanSo c(1,1), d(1,1);

    a.show(), b.show();
    c = a + b;
    c.show();

    d = b -a;
    d.show();

    d = a * b;
    d.show();

    d = a/b;
    d.show();

    d*=a;
    d.show();

    return 0;
}
