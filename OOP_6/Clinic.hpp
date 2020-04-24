#ifndef Clinic_hpp
#define Clinic_hpp

#include "Doctor.hpp"
#include <vector>

class Clinic {
private:
    std::vector<Doctor> doctors;
    std::queue<Person> patients;
    
    Doctor& findDoctor();
public:
    Clinic(std::vector<Doctor> doctors = std::vector<Doctor>(),
           std::queue<Person> patients = std::queue<Person>());
    Clinic(const Clinic& other);
    
    std::vector<Doctor> getDoctors() const;
    std::queue<Person> getPatients() const;
    
    void setDoctors(std::vector<Doctor> doctors);
    void setPatients(std::queue<Person> patients);
    
    void addDoctor(const Doctor& doctor);
    void removeDoctor(size_t index);
    Doctor& getDoctor(size_t index);
    
    void addPatient(const Person& patient);
    void removePatient(const Person& patient);
    Person& getPatient(size_t index);
    
    Clinic& operator= (const Clinic& other);
    
    void printInformation() const;
    void printDoctors() const;
    void printPatients() const;
};

#endif
