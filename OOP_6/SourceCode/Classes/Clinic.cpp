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
    doctors.push_back(doctor);
}

void Clinic::removeDoctor(size_t index) {
    if (index < 0 or index >= doctors.size()) {
        throw out_of_range("Выход за границы диапазона");
    }
    doctors.erase(doctors.begin() + index);
}

Doctor& Clinic::getDoctor(size_t index) {
    if (index < 0 or index >= doctors.size()) {
        throw out_of_range("Выход за границы диапазона");
    }
    return doctors[index];
}

void Clinic::addPatient(const Person& patient) {
    patients.push(patient);
}

void Clinic::removePatient(size_t index) {
    if (index < 0 or index >= patients.size()) {
        throw out_of_range("Выход за границы диапазона");
    }
    vector<Person> patientsCopy;
    while (!patients.empty()) {
        patientsCopy.push_back(patients.front());
        patients.pop();
    }
    patientsCopy.erase(patientsCopy.begin() + index);
    for (const auto& patient : patientsCopy) {
        patients.push(patient);
    }
}

Clinic& Clinic::operator= (const Clinic& other) {
    doctors = other.doctors;
    patients = other.patients;
    return *this;
}

void Clinic::printInformation() const {
    printDoctors();
    printPatients();
}

void Clinic::printDoctors() const {
    cout << "\nВсего " << doctors.size() << " докторов" << endl;
    for (const auto& doctor: doctors) {
        doctor.printInformation();
    }
}

void Clinic::printPatients() const {
    cout << "\nВсего " << patients.size() << " людей в очереди" << endl;
    auto patientsCopy = patients;
    while (!patientsCopy.empty()) {
        patientsCopy.front().printInformation();
        patientsCopy.pop();
    }
}

Doctor& Clinic::findDoctor() {
    auto index = 0;
    for (auto i = 1; i < doctors.size(); ++i) {
        if (doctors[index].getCuredPeopleAmount() > doctors[i].getCuredPeopleAmount()) {
            index = i;
        }
    }
    return doctors[index];
}

void Clinic::distributePatients() {
    while (!patients.empty()) {
        auto& doctor = findDoctor();
        doctor.addPatient(patients.front());
        patients.pop();
    }
}
