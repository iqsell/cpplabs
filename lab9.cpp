/*#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Ошибка выделения памяти\n";
        exit(0);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* createRing(int N) {
    Node* node = createNode(1);
    Node* temp = node;
    for (int i = 2; i <= N; ++i) {
        temp->next = createNode(i);
        temp = temp->next;
    }
    temp->next = node; // Создаем кольцо
    return node;
}

void printRing(Node* head) {
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << '\n';
}

void playGame(Node** head, int K) {
    Node *p, *q;
    int count;

    q = p = *head;

    // Создаем вектор для хранения оставшихся элементов
    std::vector<int> remainingElements;

    while (p->next != p) {
        count = K - 1;
        while (count--) {
            q = p;
            p = p->next;
        }
        q->next = p->next;

        std::cout << "Удален ребенок под номером: " << p->data << '\n';

        // Добавляем оставшиеся элементы в вектор
        Node* temp = q->next;
        do {
            remainingElements.push_back(temp->data);
            temp = temp->next;
        } while (temp != q->next);

        // Сортируем вектор
        std::sort(remainingElements.begin(), remainingElements.end());

        // Выводим отсортированный вектор
        for (int i : remainingElements) {
            std::cout << i << " ";
        }
        std::cout << '\n';

        delete p;

        p = q;

        // Очищаем вектор для следующего цикла
        remainingElements.clear();
    }

    std::cout << "Остался ребенок под номером: " << p->data << '\n';
}


int main() {
    int N, K;

    std::cout << "Введите количество детей (N): ";
    while (!(std::cin >> N)  or N < 0) {
        std::cin.clear(); // очистить текущее состояние потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // удалить значения предыдущего ввода из входного буфера
        std::cout << "Неверный ввод. Пожалуйста, введите положительное число: ";
    }

    std::cout << "Введите шаг (K): ";
    while (!(std::cin >> K) or K < 0) {
        std::cin.clear(); // очистить текущее состояние потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // удалить значения предыдущего ввода из входного буфера
        std::cout << "Неверный ввод. Пожалуйста, введите положительное число: ";
    }

    Node* head = createRing(N);

    playGame(&head, K);

    return 0;
}*/