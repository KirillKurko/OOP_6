#ifndef Doctor_hpp
#define Doctor_hpp

#include "Person.hpp"
#include "Date.hpp"
#include <stack>
#include <queue>

struct Comparator {
    bool operator() (const std::pair<Date, Person>& firstPair, const std::pair<Date, Person>& secondPair) {
        return firstPair.first > secondPair.first;
    }
};

class Doctor: public Person {
private:
    float salary;
    int experience;
    int curedPeopleAmount;
    std::stack<Person> urgentPatients;
    std::priority_queue<std::pair<Date, Person>, std::vector<std::pair<Date, Person>>, Comparator> patients;
public:
    Doctor(Fullname fullname = Fullname(),
           int age = 0,
           float salary = 0.0f,
           int experience = 0,
           int curedPeopleAmount = 0,
           std::stack<Person> urgentPatients = std::stack<Person>(),
           std::priority_queue<std::pair<Date, Person>, std::vector<std::pair<Date, Person>>, Comparator> patients = std::priority_queue<std::pair<Date, Person>, std::vector<std::pair<Date, Person>>, Comparator>());
    Doctor(const Doctor& other);
    
    float getSalary() const;
    int getExperience() const;
    int getCuredPeopleAmount() const;
    std::stack<Person> getUrgentPatients() const;
   std::priority_queue<std::pair<Date, Person>, std::vector<std::pair<Date, Person>>, Comparator> getPatients() const;
    
    void setSalary(float salary);
    void setExperience(int experience);
    void setCuredPeopleAmount(int curedPeopleAmount);
    void setUrgentPatients(std::stack<Person> urgentPatients);
    void setPatients(std::priority_queue<std::pair<Date, Person>, std::vector<std::pair<Date, Person>>, Comparator> patients);
    
    void addPatient(const Person& patient);
    void addUrgentPatient(const Person& patient);
    
    Doctor& operator= (const Doctor& other);
    
    void servePatients();
    
    void printInformation() const;
    void printUrgentPatients() const;
    void printPatients() const;
};

#endif 
