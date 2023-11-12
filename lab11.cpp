#include <iostream>
#include <string>

bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

std::string reverseString(const std::string& str) {
    if (str.length() <= 1) {
        return str;
    }
    return reverseString(str.substr(1)) + str[0];
}

int arithmeticProgression(int a, int d, int n) {
    if (n == 1) {
        return a;
    }
    return arithmeticProgression(a + d, d, n - 1);
}

int main() {
    int choice;
    std::string choiceStr;

    do {
        std::cout << "Выберите задачу:" << std::endl;
        std::cout << "1. Возведение числа в степень" << std::endl;
        std::cout << "2. Вычисление N-го члена ряда Фибоначчи" << std::endl;
        std::cout << "3. Реверс строки" << std::endl;
        std::cout << "4. Вычисление N-ого члена арифметической прогрессии" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Введите номер задачи (0-4): ";
        std::cin >> choiceStr;

        if (!isNumber(choiceStr)) {
            std::cout << "Некорректный ввод. Введите число снова." << std::endl;
        } else {
            choice = std::stoi(choiceStr);
            if (choice < 0 || choice > 4) {
                std::cout << "Некорректный ввод. Введите число снова." << std::endl;
            }
        }

        if (choice == 1) {
            int base, exponent;
            std::string baseStr, exponentStr;

            do {
                std::cout << "Введите число: ";
                std::cin >> baseStr;

                if (!isNumber(baseStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(baseStr));

            do {
                std::cout << "Введите степень: ";
                std::cin >> exponentStr;

                if (!isNumber(exponentStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(exponentStr));

            base = std::stoi(baseStr);
            exponent = std::stoi(exponentStr);

            int result = power(base, exponent);
            std::cout << base << "^" << exponent << " = " << result << std::endl;
        } else if (choice == 2) {
            int n;
            std::string nStr;

            do {
                std::cout << "Введите номер члена ряда Фибоначчи: ";
                std::cin >> nStr;

                if (!isNumber(nStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(nStr));

            n = std::stoi(nStr);

            int result = fibonacci(n);
            std::cout << "N-ый член ряда Фибоначчи: " << result << std::endl;
        } else if (choice == 3) {
            std::string str;
            std::cout << "Введите строку: ";
            std::cin.ignore();
            getline(std::cin, str);
            std::string reversed = reverseString(str);
            std::cout << "Инвертированная строка: " << reversed << std::endl;
        } else if (choice == 4) {
            int a, d, n;
            std::string aStr, dStr, nStr;

            do {
                std::cout << "Введите первый член прогрессии: ";
                std::cin >> aStr;

                if (!isNumber(aStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(aStr));

            do {
                std::cout << "Введите разность прогрессии: ";
                std::cin >> dStr;

                if (!isNumber(dStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(dStr) || std::stoi(dStr) == 0);

            do {
                std::cout << "Введите порядковый номер члена прогрессии: ";
                std::cin >> nStr;

                if (!isNumber(nStr)) {
                    std::cout << "Некорректный ввод. Введите число снова." << std::endl;
                }
            } while (!isNumber(nStr));

            a = std::stoi(aStr);
            d = std::stoi(dStr);
            n = std::stoi(nStr);

            int result = arithmeticProgression(a, d, n);
            std::cout << "N-ый член арифметической прогрессии: " << result << std::endl;
        } else if (choice == 0) {
            std::cout << "Программа завершена." << std::endl;
            break;
        }
    } while (true);

    return 0;
}