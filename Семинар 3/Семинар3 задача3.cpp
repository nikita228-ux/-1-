#include <iostream>
#include <vector>
#include <iomanip>
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
    cout << fixed << setprecision(2);
    cout << setw(10) << "Время (с)" <<"|" << setw(10) << "Скорость (м/с)\n";

    for (size_t i = 0; i < times.size(); ++i) {
        cout << setw(10) << times[i] << "|" << setw(10) << velocities[i] << endl;
    }
    return 0;
}
