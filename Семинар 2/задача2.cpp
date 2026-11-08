#include <iostream>
using namespace std;
double resistance(double ro, double V, double S, double CD) {
    double L = 0.5 * ro * V * V * S * CD;
    return L;
}

int main() {
    setlocale(LC_ALL, "RU");
    double ro, V, S, CD;

    cout << "Введите плотность воздуха ro (кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета V (м/с): ";
    cin >> V;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;

    double L = resistance(ro, V, S, CD);

    cout << endl;
    cout << "Аэродинамическое сопротивление L = " << L << " Н" << endl;

    return 0;
}
