#include <iostream>

using namespace std;

class Animal {
    uint32_t age;

  public:
    Animal(int age) { this->age = age; }

    void speak() { cout << "this animal " << age << "age :no sound\n"; }
    virtual ~Animal() {}
};

class Dog : public Animal {
  public:
    Dog(int age) : Animal(age) {}
    void speak() { cout << "gogo\n"; }
};

/*
cast Animal to original type to use function member correctly
if dynamic_cast return NULL -> ordinary a isn't Dog object
*/
void speak(Animal *a) {
    Dog *d;
    if (d = dynamic_cast<Dog *>(a)) {
        d->speak();
    } else {
        a->speak();
    }
}

int main(void) {

    Animal *a = new Animal(9);
    speak(a);
    delete a;
    a = new Dog(23);
    speak(a);
    delete a;

    return 0;
}
