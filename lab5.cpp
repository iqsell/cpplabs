/*#include <iostream>
#include <limits>
using namespace std;
int main() {
    int rows, cols;

    // Ввод количества столбцов
    cout << "Введите количество столбцов матрицы: ";
    while (!(cin >> cols) or cols <= 0) {
        cout << "Некорректный ввод. Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ввод количества строк
    cout << "Введите количество строк матрицы: ";
    while (!(cin >> rows) or rows <= 0) {
        cout << "Некорректный ввод. Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ввод матрицы
    float matrix[rows][cols];
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << i + 1, cout << " "; // номер столбца с 1
            cout << j + 1, cout << ": "; // номер строки с 1
            while (!(cin >> matrix[i][j])) {
                cout << "Некорректный ввод. Введите число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // Вывод исходной матрицы
    cout << "Исходная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Ввод номеров столбцов, которые нужно поменять местами
    int col1, col2;
    cout << "Введите номер первого столбца: ";
    while (!(cin >> col1) or col1 <= 0 or col1 > cols) {
        cout << "Некорректный ввод. Введите число от 1 до " << cols << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите номер второго столбца: ";
    while (!(cin >> col2) or col2 <= 0 or col2 > cols or col2 == col1) {
        cout << "Некорректный ввод. Введите число от 1 до " << cols << ", отличное от номера первого столбца: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Меняем местами столбцы матрицы
    for (int i = 0; i < rows; ++i) {
        float temp = matrix[i][col1 - 1];
        matrix[i][col1 - 1] = matrix[i][col2 - 1];
        matrix[i][col2 - 1] = temp;
    }

    // Вывод измененной матрицы
    cout << "Измененная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}*/