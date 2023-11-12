/*#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool isValidNumber(const string &input) {
    // Проверяем, является ли строка числом
    if (input.empty() || (input[0] != '-' && !isdigit(input[0]))) {
        return false;
    }
    for (int i = 1; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int size;
    string input;
    bool isValidSize = false;

    while (!isValidSize) {
        cout << "Введите количество элементов массива: ";
        cin >> input;

        // является ли введенное значение числом
        if (isValidNumber(input)) {
            size = stoi(input);

            // Проверяем, больше ли введенное число 0
            if (size > 0) {
                isValidSize = true;
            } else if (size < 0) {
                cout << "Введенное значение должно быть больше 0.\n";
            } else {
                cout << "Введенное значение не может быть равно 0.\n";
            }
        } else {
            cout << "Введенное значение должно быть числом.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    }

    int *array = new int[size];
    int validCount = 0;

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1, cout << ": "; // номер элемента с 1
        cin >> input;

        // является ли введенное значение числом
        if (isValidNumber(input)) {
            array[i] = stoi(input);
            validCount++;
        } else {
            cout << "Введенное значение '" << input << "' не является числом. Повторите ввод.\n";
            i--; // Возвращаемся на предыдущую итерацию, чтобы повторно ввести значение
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    }

    int count = 0;
    for (int i = 0; i < validCount; i++) {
        if (array[i] % 7 == 0) {
            count++;
        }
    }

    cout << "Количество элементов, кратных 7: " << count << endl;

    delete[] array;

    return 0;
}
 */