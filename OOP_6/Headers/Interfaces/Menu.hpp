#ifndef Menu_hpp
#define Menu_hpp

#include "../Classes/Clinic.hpp"
#include "../Utilities/CreateFunctions.hpp"

void ClinicMenu(Clinic& clinic);
void DoctorsClinicSubmenu(Clinic& clinic);
void PatientsClinicSubmenu(Clinic& clinic);
void ViewClinicSubmenu(const Clinic& clinic);

void DoctorMenu(Doctor& doctor);
void ViewDoctorSubmenu(const Doctor& doctor);
void PersonalArea(Doctor& doctor);

#endif
