#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> times;
    vector<double> velocities;

    for (double t = 0.0;; t += dt) {
        double v = v0 - g * t;
        if (v < 0.0) {
            break;
        }
        times.push_back(t);
        velocities.push_back(v);
    }
    if (velocities.empty()) {
        cout << "Даных нет! Вектор пуст\n";
        return 1;
    }
    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << fixed << setprecision(2);
    cout << setw(10) << "Время (с)" << "|" << setw(10) << "Скорость (м/с)\n";

    for (size_t i = 0; i < times.size(); ++i) {
        cout << setw(10) << times[i] << "|" << setw(10) << velocities[i] << endl;
    }
    cout << fixed << setprecision(2);

    cout << " Задача 4: Средняя скорость\n";
    cout << "Сумма всех скоростей: " << sum << " м/с\n";
    cout << "Количество измерений: " << velocities.size() << "\n";
    cout << "Средняя скорость: " << avg << " м/с\n";
    return 0;
}