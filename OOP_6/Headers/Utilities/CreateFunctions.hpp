#ifndef CreateFunctions_hpp
#define CreateFunctions_hpp

#include <iostream>
#include <vector>
#include <queue>
#include "../Classes/Clinic.hpp"
#include "../Utilities/Date.hpp"
#include "../Classes/Doctor.hpp"

Clinic CreateClinic();
std::vector<Doctor> CreateDoctors();
Doctor CreateDoctor();
std::queue<Person> CreatePatients();
Person CreatePerson();
Fullname CreateFullname();
Date CreateDate();
Time CreateTime();

#endif
