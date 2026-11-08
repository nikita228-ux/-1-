#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double m, T, L, D;

    cout << "Введите массу самолета m (кг): ";
    cin >> m;
    cout << "Введите тягу двигателя T (Н): ";
    cin >> T;
    cout << "Введите подъемную силу L (Н): ";
    cin >> L;
    cout << "Введите силу сопротивления D (Н): ";
    cin >> D;

    double a = (T - D) / m;

    cout << "\nГоризонтальное ускорение a = " << a << " м/с^2" << endl;
    cout << "Определен режим полета: ";

    if (a > 0.5) {
        cout << "набор высоты " << endl;
    }
    else if (a >= 0.0 && a <= 0.5) {
        cout << "горизонтальный полет " << endl;
    }
    else {
        cout << "снижение" << endl;
    }

    return 0;
}
