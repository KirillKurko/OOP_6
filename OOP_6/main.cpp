#include <iostream>
#include "Clinic.hpp"
#include "CreateFunctions.hpp"

using namespace std;

void ClinicMenu(Clinic& clinic);
void DoctorsClinicSubmenu(Clinic& clinic);
void PatientsClinicSubmenu(Clinic& clinic);
void ViewClinicSubmenu(const Clinic& clinic);

void DoctorMenu(Doctor& doctor);
void ViewDoctorSubmenu(const Doctor& doctor);
void PersonalArea(Doctor& doctor);

int main() {
    auto selection = 0;
    Clinic clinic = CreateClinic();
    while (true) {
        cout << "\n1 - Меню клиники\n2 - Меню доктора\n3 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                ClinicMenu(clinic);
                break;
            case 2: {
                auto index = 0;
                cout << "Введите индекс доктора для работы: ";
                cin >> index;
                try {
                    DoctorMenu(clinic.getDoctor(index));
                }
                catch (const out_of_range& exception) {
                    cout << exception.what() << endl;
                }
                break;
            }
            case 3: default:
                cout << "Завершение работы" << endl;
                return 0;
        }
    }
}

void ClinicMenu(Clinic& clinic) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Доктора\n2 - Пациенты\n3 - Просмотреть информацию\n4 - Распределить пациентов по докторам\n5 - Назад" << endl;
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                DoctorsClinicSubmenu(clinic);
                break;
            case 2:
                PatientsClinicSubmenu(clinic);
            case 3:
                ViewClinicSubmenu(clinic);
                break;
            case 4:
                clinic.distributePatients();
                break;
            case 5: default:
                cout << "Выход из меню клиники" << endl;
                return;
        }
    }
}

void DoctorsClinicSubmenu(Clinic& clinic) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Добавить доктора\n2 - Удалить доктора\n3 - Назад" << endl;
        cout << "Выберите пунтк меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1: {
                auto doctor = CreateDoctor();
                clinic.addDoctor(doctor);
                break;
            }
            case 2: {
                auto index = 0;
                cout << "Введите индекс доктора для удаления: ";
                cin >> index;
                cin.ignore();
                try {
                    clinic.removeDoctor(index);
                }
                catch (const out_of_range& exception) {
                    cout << exception.what() << endl;
                }
                break;
            }
            case 3: default:
                cout << "Выход из подменю докторов" << endl;
                return;
        }
    }
}

void PatientsClinicSubmenu(Clinic& clinic) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Добавить пациента\n2 - Удалить пациента\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1: {
                auto patient = CreatePerson();
                clinic.addPatient(patient);
                break;
            }
            case 2: {
                auto index = 0;
                cout << "Введите индекс пациента для удаления: ";
                cin >> index;
                cin.ignore();
                try {
                    clinic.removePatient(index);
                }
                catch (const out_of_range& exception) {
                    cout << exception.what() << endl;
                }
                break;
            }
            case 3: default:
                cout << "Выход из подменю просмотра" << endl;
                return;
        }
    }
}

void ViewClinicSubmenu(const Clinic& clinic) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Просмотреть всю информацию\n2 - Просмотреть информацию о докторах\n3 - Просмотреть информацию о пациентах\n4 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                clinic.printInformation();
                break;
            case 2:
                clinic.printDoctors();
                break;
            case 3:
                clinic.printPatients();
                break;
            case 4: default:
                cout << "Выход из подменю просмотра" << endl;
                return;
        }
    }
}

void DoctorMenu(Doctor& doctor) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Обслужить пациентов\n2 - Просмотреть пациентов\n3 - Личный кабинет\n4 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                doctor.servePatients();
                break;
            case 2:
                ViewDoctorSubmenu(doctor);
                break;
            case 3:
                PersonalArea(doctor);
                break;
            case 4: default:
                cout << "Выход из меню доктора" << endl;
                return;
        }
    }
}

void ViewDoctorSubmenu(const Doctor& doctor) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Просмотреть всю информацию\n2 - Просмотреть срочных пациентов\n3 - Просмотреть пациентов\n4 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1:
                doctor.printInformation();
                break;
            case 2:
                doctor.printUrgentPatients();
                break;
            case 3:
                doctor.printPatients();
                break;
            case 4: default:
                cout << "Выход из подменю просмотра" << endl;
                return;
        }
    }
}

void PersonalArea(Doctor& doctor) {
    auto selection = 0;
    while (true) {
        cout << "\n1 - Изменить имя" <<
                "\n2 - Изменить фамилию" <<
                "\n3 - Изменить возраст" <<
                "\n4 - Изменить зарплату" <<
                "\n5 - Изменить опыт работы"
                "\n6 - Изменить количество вылеченных пациентов" <<
                "\n7 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        cin >> selection;
        cin.ignore();
        switch (selection) {
            case 1: {
                auto fullname = doctor.getFullname();
                string name;
                cout << "Введите имя: ";
                getline(cin, name);
                fullname.setName(name);
                doctor.setFullname(fullname);
                break;
            }
            case 2: {
                auto fullname = doctor.getFullname();
                string surname;
                cout << "Введите фамилию: ";
                getline(cin, surname);
                fullname.setSurname(surname);
                doctor.setFullname(fullname);
                break;
            }
            case 3: {
                auto age = 0;
                cout << "Введите возраст: ";
                cin >> age;
                cin.ignore();
                doctor.setAge(age);
                break;
            }
            case 4: {
                auto salary = 0.0f;
                cout << "Введите зарплату: ";
                cin >> salary;
                cin.ignore();
                doctor.setSalary(salary);
                break;
            }
            case 5: {
                auto age = 0;
                cout << "Введите возраст: ";
                cin >> age;
                cin.ignore();
                doctor.setAge(age);
                break;
            }
            case 6: {
                auto curedPatientsAmount = 0;
                cout << "Введите количество вылеченных пациентов: ";
                cin >> curedPatientsAmount;
                cin.ignore();
                doctor.setCuredPeopleAmount(curedPatientsAmount);
                break;
            }
            case 7: default:
                cout << "Выход из личного кабинета" << endl;
                return;
        }
    }
}
