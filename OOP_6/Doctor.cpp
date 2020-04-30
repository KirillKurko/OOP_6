#include "Doctor.hpp"

using namespace std;

Doctor::Doctor(Fullname fullname, int age, float salary, int experience,
               int curedPeopleAmount,
               stack<Person> urgentPatients,
               priority_queue<Person> patients) : Person(fullname, age) {
    this->salary = salary;
    this->experience = experience;
    this->curedPeopleAmount = curedPeopleAmount;
    this->urgentPatients = urgentPatients;
    this->patients = patients;
}

Doctor::Doctor(const Doctor& other) : Person(other) {
    salary = other.salary;
    experience = other.experience;
    curedPeopleAmount = other.curedPeopleAmount;
    urgentPatients = other.urgentPatients;
    patients = other.patients;
}

float Doctor::getSalary() const {
    return salary;
}

int Doctor::getExperience() const {
    return experience;
}

int Doctor::getCuredPeopleAmount() const {
    return curedPeopleAmount;
}

stack<Person> Doctor::getUrgentPatients() const {
    return urgentPatients;
}

priority_queue<Person> Doctor::getPatients() const {
    return patients;
}

void Doctor::setSalary(float salary) {
    this->salary = salary;
}

void Doctor::setExperience(int experience) {
    this->experience = experience;
}

void Doctor::setCuredPeopleAmount(int curedPeopleAmount) {
    this->curedPeopleAmount = curedPeopleAmount;
}

void Doctor::setUrgentPatients(stack<Person> urgentPatients) {
    this->urgentPatients = urgentPatients;
}

void Doctor::setPatients(priority_queue<Person> patients) {
    this->patients = patients;
}

void Doctor::addPatient(const Person& patient) {
    patients.push(patient);
}

void Doctor::addUrgentPatient(const Person& patient) {
    urgentPatients.push(patient);
}

Doctor& Doctor::operator= (const Doctor& other) {
    Person::operator=(other);
    salary = other.salary;
    experience = other.experience;
    curedPeopleAmount = other.curedPeopleAmount;
    urgentPatients = other.urgentPatients;
    patients = other.patients;
    return *this;
}

void Doctor::servePatients() {
    auto urgentPatientsAmount = urgentPatients.size();
    while (!urgentPatients.empty()) {
        urgentPatients.top().printInformation();
        urgentPatients.pop();
    }
    cout << "Обслужено срочных пациентов: " << urgentPatientsAmount << endl;
    
    auto patientsAmount = patients.size();
    while (!patients.empty()) {
        patients.top().printInformation();
        patients.pop();
    }
    cout << "Обслужено пациентов: " << patientsAmount << endl;
    curedPeopleAmount += urgentPatientsAmount + patientsAmount;
}


void Doctor::printInformation() const {
    Person::printInformation();
    cout << "Зарплата: " << salary << endl
    << "Опыт работы: " << experience << endl
    << "Количество вылеченных пациентов: " << curedPeopleAmount << endl;
    printUrgentPatients();
    printPatients();
}

void Doctor::printUrgentPatients() const {
    auto printCopy =  urgentPatients;
    while (!printCopy.empty()) {
        printCopy.top().printInformation();
        printCopy.pop();
    }
}

void Doctor::printPatients() const {
    auto printCopy =  patients;
    while (!printCopy.empty()) {
        printCopy.top().printInformation();
        printCopy.pop();
    }
}
