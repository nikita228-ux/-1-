#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double h, ay;

    cout << "Введите высоту h (м): ";
    cin >> h;

    cout << "Введите вертикальное ускорение ay (м/с^2): ";
    cin >> ay;

    if (h <= 0 || ay <= 0) {
        cout << "Ошибка! Высота и ускорение должны быть строго больше 0." << endl;
        return 1; 
    }

    double t = sqrt(2 * h / ay);

    cout << endl;
    cout << "Время набора высоты t = " << t << " с" << endl;

    return 0;
}