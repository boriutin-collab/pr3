#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

void task_if8();
void task_if33();
void task_geom36();

int main() {
    SetConsoleOutputCP(CP_UTF8);   // щоб в консолі були українські букви
    task_if8();
    task_if33();
    task_geom36();
    return 0;
}

// If8. Вивести спочатку більше число, потім менше
void task_if8() {
    double a, b;
    cout << "Завдання 1. If8\nВведіть два числа: ";
    cin >> a >> b;
    if (!cin) {                       // перевірка: ввели не числа
        cout << "Некоректні дані!" << endl;
        return;
    }
    if (a > b)
        cout << "Більше: " << a << ", менше: " << b << endl;
    else
        cout << "Більше: " << b << ", менше: " << a << endl;
}

// If33. p(x) = x^3 (x <= 1), 2x + 1 (1 < x < 4), 9 (x >= 4)
void task_if33() {
    double x, p;
    cout << "\nЗавдання 2. If33\nВведіть x: ";
    cin >> x;
    if (!cin) {
        cout << "Некоректні дані!" << endl;
        return;
    }
    if (x <= 1)
        p = x * x * x;
    else if (x < 4)
        p = 2 * x + 1;
    else
        p = 9;
    cout << "p(x) = " << p << endl;
}

// Геометрія, варіант 36. Чи потрапляє точка в темно-коричневу область
void task_geom36() {
    double r, x, y;
    cout << "\nЗавдання 3. Геометрія 36\nВведіть радіус r: ";
    cin >> r;
    if (!cin || r <= 0) {
        cout << "Некоректний радіус!" << endl;
        return;
    }
    cout << "Введіть точку (x y): ";
    cin >> x >> y;
    if (!cin) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    // центр кола (c, c), коло перетинає осі в точках (d, 0) і (0, d)
    double c = r / sqrt(2.0);
    double d = r * sqrt(2.0);

    // трикутник (0,0), (0,d), (c,c)
    bool inTriangle = x >= 0 && y >= x && x + y <= d;
    // сегмент кола під віссю OX
    bool inSegment = y < 0 && pow(x - c, 2) + pow(y - c, 2) <= r * r;

    if (inTriangle || inSegment)
        cout << "Точка належить області" << endl;
    else
        cout << "Точка не належить області" << endl;
}
