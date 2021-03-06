#ifndef Person_hpp
#define Person_hpp

#include "../Utilities/Fullname.hpp"

class Person {
    friend bool operator< (const Person& first, const Person& second);
protected:
    Fullname fullname;
    int age;
public:
    Person(Fullname fullname = Fullname(), int age = 0);
    Person(const Person& other);
    
    Fullname getFullname() const;
    int getAge() const;
    
    void setFullname(Fullname fullname);
    void setAge(int age);
    
    Person& operator= (const Person& other);
    
    void printInformation() const;
};

#endif
