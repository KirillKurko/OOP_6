#ifndef CreateFunctions_hpp
#define CreateFunctions_hpp

#include <iostream>
#include "Clinic.hpp"

Clinic CreateClinic();
std::vector<Doctor> CreateDoctors();
Doctor CreateDoctor();
std::queue<Person> CreatePatients();
Person CreatePeron();
Fullname CreateFullname();

#endif
