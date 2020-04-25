#include "CreateFunctions.hpp"

using namespace std;

Clinic CreateClinic() {
    auto doctors = CreateDoctors();
    auto patients = CreatePatients();
    return Clinic(doctors, patients);
}

vector<Doctor> CreateDoctors() {
    auto doctorsAmount = 0;
    cout << "Введите количество докторов для добавления: ";
    cin >> doctorsAmount;
    cin.ignore();
    vector<Doctor> doctors(doctorsAmount);
    for (auto& doctor : doctors) {
        doctor = CreateDoctor();
    }
    return doctors;
}

Doctor CreateDoctor() {
    auto person = CreatePeron();
    auto salary = 0.0f;
    cout << "Введите зарплату: ";
    cin >> salary;
    auto experience = 0;
    cout << "Введите опыт работы: ";
    cin >> experience;
    cin.ignore();
    auto curedPeopleAmount = 0;
    cout << "Введите количество вылеченных людей: ";
    cin >> curedPeopleAmount;
    cin.ignore();
    return Doctor(person.getFullname(), person.getAge(), salary, experience, curedPeopleAmount);
}

queue<Person> CreatePatients() {
    auto patientsAmount = 0;
    cout << "Введите количество пациентов для добавления: ";
    cin >> patientsAmount;
    cin.ignore();
    queue<Person> patients;
    for (auto i = 0; i < patientsAmount; ++i) {
        auto patient = CreatePeron();
        patients.push(patient);
    }
    return patients;
}

Person CreatePeron() {
    auto fullname = CreateFullname();
    auto age = 0;
    cout << "Введите возраст: ";
    cin >> age;
    cin.ignore();
    return Person(fullname, age);
}

Fullname CreateFullname() {
    string name;
    cout << "Введите имя: ";
    cin >> name;
    cin.ignore();
    string surname;
    cout << "Введите фамилию: ";
    cin >> surname;
    cin.ignore();
    return Fullname(name, surname);
}
