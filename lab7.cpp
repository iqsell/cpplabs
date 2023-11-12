/*#include <iostream>
#include <cmath>

using namespace std;
struct Date {
    int day;
    int month;
    int year;

};

bool isValidDate(const Date &date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Проверяем корректность года
    if (date.year <= 0)
        return false;

    // Проверяем корректность месяца
    if (date.month < 1 || date.month > 12)
        return false;

    // Проверяем корректность дня
    int maxDay = daysInMonth[date.month - 1];
    if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0))
        maxDay = 29;
    if (date.day < 1 || date.day > maxDay)
        return false;

    return true;
}

int calculateDaysBetweenDates(const Date &date1, const Date &date2) {
    if (!isValidDate(date1) || !isValidDate(date2)) {
        cout << "Некорректная дата!\n";
        return -1;
    }

    const Date &startDate = (date1.year < date2.year) or (date1.year == date2.year and date1.month < date2.month) or
                            (date1.year == date2.year and date1.month == date2.month and date1.day < date2.day)
                            ? date1 : date2;
    const Date &endDate = (&startDate == &date1) ? date2 : date1;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays1 = startDate.year * 365 + startDate.day;
    for (int i = 0; i < startDate.month - 1; i++) {
        totalDays1 += daysInMonth[i];
    }
    totalDays1 += floor((startDate.year - 1) / 4.0);
    int totalDays2 = endDate.year * 365 + endDate.day;
    for (int i = 0; i < endDate.month - 1; i++) {
        totalDays2 += daysInMonth[i];
    }
    totalDays2 += floor((endDate.year - 1) / 4.0);
    return totalDays2 - totalDays1;
}

int main() {
    Date date1, date2;
    cout << "Введите дату 1 (число, месяц, год): ";
    while (!(cin >> date1.day >> date1.month >> date1.year) || !isValidDate(date1)) {
        cout << "Некорректная дата! Введите дату 1 снова (число, месяц, год): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Введите дату 2 (число, месяц, год): ";
    while (!(cin >> date2.day >> date2.month >> date2.year) || !isValidDate(date2)) {
        cout << "Некорректная дата! Введите дату 2 снова (число, месяц, год): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int days = calculateDaysBetweenDates(date1, date2);
    if (days != -1) {
        cout << "Количество дней между датами: " << days << "\n";
    }
    return 0;
}*/