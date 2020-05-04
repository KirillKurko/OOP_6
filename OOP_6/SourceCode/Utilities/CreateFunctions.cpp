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
    auto person = CreatePerson();
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
        auto patient = CreatePerson();
        patients.push(patient);
    }
    return patients;
}

Person CreatePerson() {
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

Date CreateDate() {
    auto time = CreateTime();
    auto day = 0;
    cout << "Введите день: ";
    cin >> day;
    cin.ignore();
    auto month = 0;
    cout << "Введите месяц: ";
    cin >> month;
    cin.ignore();
    auto year = 0;
    cout << "Введите год: ";
    cin >> year;
    cin.ignore();
    return Date(time, day, month, year);
}

Time CreateTime() {
    auto hours = 0;
    cout << "Введите часы: ";
    cin >> hours;
    cin.ignore();
    auto minutes = 0;
    cout << "Введите минуты: ";
    cin >> minutes;
    cin.ignore();
    auto seconds = 0;
    cout << "Введите секунды: ";
    cin >> seconds;
    cin.ignore();
    return Time(hours, minutes, seconds);
}
