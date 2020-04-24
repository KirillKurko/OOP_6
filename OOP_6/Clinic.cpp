#include "Clinic.hpp"

using namespace std;

Clinic::Clinic(vector<Doctor> doctors, queue<Person> patients) : doctors(doctors), patients(patients) {}

Clinic::Clinic(const Clinic& other) {
    doctors = other.doctors;
    patients = other.patients;
}

vector<Doctor> Clinic::getDoctors() const {
    return doctors;
}

queue<Person> Clinic::getPatients() const {
    return patients;
}

void Clinic::setDoctors(vector<Doctor> doctors) {
    this->doctors = doctors;
}

void Clinic::setPatients(queue<Person> patients) {
    this->patients = patients;
}

void Clinic::addDoctor(const Doctor& doctor) {
    
}

void Clinic::removeDoctor(size_t index) {
    
}

Doctor& Clinic::getDoctor(size_t index) {
    
}

void Clinic::addPatient(const Person& patient) {
    
}

void Clinic::removePatient(const Person& patient) {
    
}

Person& Clinic::getPatient(size_t index) {
    
}

Clinic& Clinic::operator= (const Clinic& other) {
    
}

void Clinic::printInformation() const {
    
}

void Clinic::printDoctors() const {
    
}

void Clinic::printPatients() const {
    
}

Doctor& Clinic::findDoctor() {
    
}
