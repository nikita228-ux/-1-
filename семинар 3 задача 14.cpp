#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    
    vector<double> y = { 0.0, 45.1, 80.4, 105.9, 121.6, 127.5, 123.6, 109.9, 86.4, 53.1, 10.0, -42.9 };

    cout << "Координаты y: ";
    for (double v : y) cout << v << " ";
    cout << "\n";

    vector<double> displacements(y.size());
    adjacent_difference(y.begin(), y.end(), displacements.begin());

    cout << "Смещения: ";
    for (double d : displacements) cout << d << " ";
    cout << "\n";

    double total_path = 0.0;
    for (double d : displacements) {
        total_path += abs(d);
    }
    cout << "Суммарный путь ракеты: " << total_path << " м\n";

    return 0;
}