#ifndef CreateFunctions_hpp
#define CreateFunctions_hpp

#include <iostream>
#include "Clinic.hpp"

Clinic CreateClinic();
std::vector<Doctor> CreateDoctors();
Doctor CreateDoctor();
std::queue<Person> CreatePatients();
Person CreatePerson();
Fullname CreateFullname();

#endif
