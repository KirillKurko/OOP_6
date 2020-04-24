#include "Person.hpp"

using namespace std;

Person::Person(Fullname fullname, int age) : fullname(fullname), age(age) {}

Person::Person(const Person& other) {
    fullname = other.fullname;
    age = other.age;
}

Fullname Person::getFullname() const {
    return fullname;
}

int Person::getAge() const {
    return age;
}

void Person::setFullname(Fullname fullname) {
    this->fullname = fullname;
}

void Person::setAge(int age) {
    this->age = age;
}

Person& Person::operator= (const Person& other) {
    fullname = other.fullname;
    age = other.age;
    return *this;
}


void Person::printInformation() const {
    cout << "Fullname: " << fullname << endl <<
            "Age: " << age << endl;
}
