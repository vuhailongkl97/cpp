#include <iostream>

using namespace std;


class Animal
{
    public:
    virtual void move() {
        cout << "move from Animal" << endl;
    }
};

class Dog: public Animal {
    public:
    void move() override
    {
        cout << "move from Dog" << endl;
    }
};

int main(void)
{
    Animal *a = new Dog;

    a->move();
    delete a;
    a = new Animal;
    a->move();

    return 0;
}
