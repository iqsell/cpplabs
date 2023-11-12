/*#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <locale>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Patient {
    string name;
    string address;
    int birthYear;
    int districtNumber;
    bool hasChronicIllness;
};

vector<Patient> database;

// создание записи
void createRecord() {
    Patient newPatient;

    while (true) {
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, newPatient.name);
        bool validName = true;
        for (char c: newPatient.name) {
            if (!isalpha(c)) {
                validName = false;
                break;
            }
        }
        if (validName) {
            break;
        }
        cout << "Некорректный ввод имени. Имя может содержать только буквы.\n";
    }


    while (true) {
        cout << "Введите адрес: ";
        getline(cin, newPatient.address);
        bool validAddress = true;
        for (char c: newPatient.address) {
            if (!isalpha(c) && !isspace(c)) {
                validAddress = false;
                break;
            }
        }
        if (validAddress) {
            break;
        }
        cout << "Некорректный ввод адреса. Адрес может содержать только буквы и пробелы.\n";
    }


    while (true) {
        cout << "Введите год рождения: ";
        cin >> newPatient.birthYear;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод года рождения. Введите число.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Введите номер участка: ";
        cin >> newPatient.districtNumber;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод номера участка. Введите число.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Есть ли хронические болезни? (1 - да, 0 - нет): ";
        int illnessInput;
        cin >> illnessInput;
        if (cin.fail() || (illnessInput != 0 && illnessInput != 1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод хронических болезней. Введите 0 или 1.\n";
        } else {
            newPatient.hasChronicIllness = (illnessInput == 1);
            break;
        }
    }

    database.push_back(newPatient);
}

//изменение записи
void modifyRecord() {
    cout << "Введите имя записи, которую хотите изменить: ";
    cin.ignore();
    string name;
    getline(cin, name);

    // Привести введенное имя к нижнему регистру
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    vector<int> matchingIndices;
    for (int i = 0; i < database.size(); i++) {
        std::string dataName = database[i].name;
        transform(dataName.begin(), dataName.end(), dataName.begin(), ::tolower);

        if (dataName.find(name) != string::npos) {
            matchingIndices.push_back(i);
        }
    }

    if (matchingIndices.empty()) {
        cout << "Записи с данным именем не найдены.\n";
        return;
    } else if (matchingIndices.size() > 1) {
        cout << "Найдено несколько похожих записей. Выберите id записи, которую хотите изменить:\n";
        for (int index: matchingIndices) {
            cout << "ID: " << index << "\n"
                 << "Name: " << database[index].name << "\n";
        }

        int id;
        cout << "Введите id записи, которую хотите изменить: ";
        cin >> id;

        if (id < 0 || id >= database.size() ||
            find(matchingIndices.begin(), matchingIndices.end(), id) == matchingIndices.end()) {
            cout << "Некорректный id записи. Изменение отменено.\n";
            return;
        }

        matchingIndices = {id};
    }

    for (int index: matchingIndices) {
        int choice;
        do{
            cout << "Выберите номер поля для изменения:\n";
            cout << "1: изменить имя\n";
            cout << "2: изменить адрес\n";
            cout << "3: изменить год рождения\n";
            cout << "4: изменить номер участка\n";
            cout << "5: изменить хронические болезни\n";
            cout << "6: прекратить изменение(вернуться в главное меню)\n";

            cin >> choice;
            cin.ignore();

            if(choice == 6){
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Введите новое имя: ";
                    getline(cin, database[index].name);
                    break;
                case 2:
                    cout << "Введите новый адрес: ";
                    getline(cin, database[index].address);
                    break;
                case 3:
                    cout << "Введите новый год рождения: ";
                    cin >> database[index].birthYear;
                    cin.ignore();
                    break;
                case 4:
                    cout << "Введите новый номер участка: ";
                    cin >> database[index].districtNumber;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Есть ли хронические болезни? (1 - да, 0 - нет): ";
                    cin >> database[index].hasChronicIllness;
                    cin.ignore();
                    break;
                default:
                    cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 6.\n";
            }
        } while (choice >= 1 && choice <= 5);
    }
}



//удаление записи
void deleteRecord() {
    string name;

    cout << "Введите имя записи, которую хотите удалить: ";
    cin.ignore();
    getline(cin, name);
    // Привести введенное имя к нижнему регистру
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    vector<int> matchingIndices;


    for (int i = 0; i < database.size(); i++) {
// Привести имя из базы данных к нижнему регистру
        std::string dataName = database[i].name;
        transform(dataName.begin(), dataName.end(), dataName.begin(), ::tolower);
        transform(dataName.begin(), dataName.end(), dataName.begin(), ::tolower);
        if (database[i].name.find(name) != string::npos) {
            matchingIndices.push_back(i);
        }
    }
    // Вывод всех похожих совпадений
    if (matchingIndices.empty()) {
        cout << "Записи с данным именем не найдены.\n";
        return;
    } else if (matchingIndices.size() > 1) {
        cout << "Найдено несколько похожих записей. Выберите id записи, которую хотите удалить:\n";
        for (int index: matchingIndices) {
            cout << "ID: " << index << "\n"
                 << "Name: " << database[index].name << "\n";
        }

        int id;
        cout << "Введите id записи, которую хотите удалить: ";
        cin >> id;

        auto it = find(matchingIndices.begin(), matchingIndices.end(), id);
        if (it == matchingIndices.end()) {
            cout << "Некорректный id записи. Удаление отменено.\n";
            return;
        }

        database.erase(database.begin() + *it);
    } else {
        database.erase(database.begin() + matchingIndices[0]);
    }

    cout << "Запись успешно удалена.\n";
}

//поиск записи
void searchRecord() {
    string name;
    cout << "Введите имя для поиска: ";
    cin.ignore();
    getline(cin, name);
    // Привести введенное имя к нижнему регистру
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    vector<int> matchingIndices;


    for (int i = 0; i < database.size(); i++) {
// Привести имя из базы данных к нижнему регистру
        std::string dataName = database[i].name;
        transform(dataName.begin(), dataName.end(), dataName.begin(), ::tolower);
        transform(dataName.begin(), dataName.end(), dataName.begin(), ::tolower);
        if (database[i].name.find(name) != string::npos) {
            matchingIndices.push_back(i);
        }
    }

    // Преобразуем введенное имя в нижний регистр
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    bool found = false; // Флаг для проверки, были ли найдены совпадения

    for (int i = 0; i < database.size(); i++) {
        // Преобразуем имя в базе данных в нижний регистр
        string databaseName = database[i].name;
        transform(databaseName.begin(), databaseName.end(), databaseName.begin(), ::tolower);

        if (databaseName.find(name) != string::npos) { // Проверяем, содержит ли имя в базе данных искомые символы
            cout << "Запись найдена:\n";
            cout << "Имя: " << database[i].name << "\n";
            cout << "Адрес: " << database[i].address << "\n";
            cout << "Год рождения: " << database[i].birthYear << "\n";
            cout << "Номер участка: " << database[i].districtNumber << "\n";
            cout << "Хронические болезни: " << (database[i].hasChronicIllness ? "Да" : "Нет") << "\n";
            found = true; // флаг true,если были найдены совпадения
        }
    }

    if (!found) {
        cout << "Не найдено записи с указанными символами\n";
    }
}


// вывод всех записей
void listAllRecords() {
    for (int i = 0; i < database.size(); i++) {
        cout << "ID: " << i << "\n"
             << "Name: " << database[i].name << "\n"
             << "Address: " << database[i].address << "\n"
             << "Birth Year: " << database[i].birthYear << "\n"
             << "District Number: " << database[i].districtNumber << "\n"
             << "Has chronic illness: " << (database[i].hasChronicIllness ? "Yes" : "No") << "\n\n";
    }
}

int main() {
    int choice;
    do {
        cout << "1. Создать запись\n"
             << "2. Изменить запись\n"
             << "3. Удалить запись\n"
             << "4. Поиск записи по имени\n"
             << "5. Список всех записей\n"
             << "0. Выход\n"
             << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createRecord();
                break;
            case 2:
                modifyRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                listAllRecords();
                break;
            case 0:
                cout << "Выход из программы\n";
                break;
            default:
                cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    return 0;
}*/