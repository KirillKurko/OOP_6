#include "Fullname.hpp"

using namespace std;

Fullname::Fullname(string name, string surname) : name(name), surname(surname) {
}

Fullname::Fullname(const Fullname& other) {
    name = other.name;
    surname = other.surname;
}

string Fullname::getName() const {
    return name;
}

string Fullname::getSurname() const {
    return surname;
}

void Fullname::setName(string name) {
    this->name = name;
}

void Fullname::setSurname(string surname) {
    this->surname = surname;
}

Fullname& Fullname::operator= (const Fullname& other) {
    name = other.name;
    surname = other.surname;
    return *this;
}

void Fullname::printInformation() const {
    cout << name << " " << surname;
}

ostream& operator<< (ostream& stream, const Fullname& fullname) {
    stream << fullname.name << " " << fullname.surname;
    return stream;
}

istream& operator>> (istream& stream, Fullname fullname) {
    stream >> fullname.name;
    stream.ignore(1);
    stream >> fullname.surname;
    return stream;
}
