#ifndef Fullname_hpp
#define Fullname_hpp

#include <iostream>
#include <string>

class Fullname {
    friend std::ostream& operator<< (std::ostream& stream, const Fullname& fullname);
    friend std::istream& operator>> (std::istream& stream, Fullname fullname);
private:
    std::string name;
    std::string surname;
public:
    Fullname(std::string name = std::string(),
             std::string surname = std::string());
    Fullname(const Fullname& other);
    
    std::string getName() const;
    std::string getSurname() const;
    
    void setName(std::string name);
    void setSurname(std::string surname);
    
    Fullname& operator= (const Fullname& other);
    
    void printInformation() const;
};

#endif
