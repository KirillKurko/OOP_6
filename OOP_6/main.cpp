#include <iostream>
#include "Headers/Interfaces/Menu.hpp"

using namespace std;

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
