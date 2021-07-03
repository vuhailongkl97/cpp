#include <iostream>
#include <string>

using namespace std;

class Person{
    int age;
    string name;
   public:
    Person():Person(24, "default"){};
    Person(int age, string name);
    void show();
    string getName() { return this->name; }
    int getAge() { return this->age; }
};

void Person::show(){
    cout << "age is " << this->age << " - "<< this->name<< endl;
}

Person::Person(int age, string name)
{
    this->age = age;
    this->name = name;
}

class Employee : public Person{
    string id;
    public:
    Employee(int, string, string);
    void show();
};

Employee::Employee(int age, string name, string id):Person(age, name) {
    this->id = id;
}

void Employee::show()
{
    cout << "id is " << this->id << " - " << this->getName() << " - " << \
        this->getAge() << endl;
}

int main(void)
{
    Person p1(12, "longkl");
    Person p2;
    p1.show();
    p2.show();

    Employee e1(23, "long", "99978");
    e1.show();

    return 0;
}
