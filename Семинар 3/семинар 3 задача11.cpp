#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> times;
    vector<double> heights;

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (h < 0.0) break;
    }

    auto max_it = max_element(heights.begin(), heights.end());
    double max_h = *max_it;
    size_t idx = distance(heights.begin(), max_it);
    double t_max = times[idx];

    cout << fixed << setprecision(2);
    cout << "Максимальная высота: " << max_h << " м\n";
    cout << "Достигнута в момент: t = " << t_max << " с\n";
    cout << "Индекс: " << idx << "\n";

    return 0;
}
