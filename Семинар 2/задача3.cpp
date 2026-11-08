#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const double g = 9.81;

    double m, L, D, T;

    cout << "Введите массу самолета m (кг): ";
    cin >> m;

    cout << "Введите подъемную силу L (Н): ";
    cin >> L;

    cout << "Введите силу сопротивления D (Н): ";
    cin >> D;

    cout << "Введите тягу двигателя T (Н): ";
    cin >> T;

    double a = (T - D) / m;

    double ay = (L - m * g) / m;

    cout << endl;
    cout << "Горизонтальное ускорение a = " << a << " м/с^2" << endl;
    cout << "Вертикальное ускорение ay = " << ay << " м/с^2" << endl;
    return 0;
}
