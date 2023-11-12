/*#include <iostream>
#include <vector>
#include <string>

int countDifferences(const std::string &str1, const std::string &str2) {
    int count = 0;
    int lengthDiff = std::abs(int(str1.length()) - int(str2.length()));
    count += lengthDiff; // учитываем разницу в длине слов

    int substrLength = std::min(str1.length(), str2.length());
    for (int i = 0; i < substrLength; i++) {
        if (str1.substr(i, 1) != str2.substr(i, 1)) {
            count++;
        }
    }
    return count;
}

std::string substr(const std::string &str, int startPos, int length) {
    return str.substr(startPos, length);
}

int main() {
    std::vector<std::string> words;
    std::string input;

    // цикл для получения слов с клавиатуры
    while (true) {
        std::cin >> input;
        if (input == "-") {
            break;
        }
        words.push_back(input);
    }

    // поиск минимального количества отличий
    int minDifferences = countDifferences(words[0], words[1]);
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            int differences = countDifferences(words[i], words[j]);
            if (differences < minDifferences) {
                minDifferences = differences;
            }
        }
    }

    // вывод слов с минимальным количеством отличий
    std::cout << "Наименьшее количество отличий: " << minDifferences << std::endl;

    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            int differences = countDifferences(words[i], words[j]);
            if (differences == minDifferences) {
                std::cout << "Слово 1: " << words[i] << std::endl;
                std::cout << "Слово 2: " << words[j] << std::endl;
            }
        }
    }

    return 0;
}*/