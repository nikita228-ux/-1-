#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<double> h = { 10.5, 19.2, 31.8, 39.1, 52.3, 58.7, 71.4, 79.5 };

    size_t n = h.size();
    vector<double> smoothed(n);

    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];

    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    cout << fixed << setprecision(2);
    cout << "Сглаживание траектории:\n";
    cout << setw(8) << "Индекс" << "|" << setw(12) << "С шумом" << "|" << setw(12) << "Сглаженное" << "\n";
  
    for (size_t i = 0; i < n; ++i) {
        cout << setw(8) << i<< "|" << setw(12) << h[i]<< "|" << setw(12) << smoothed[i] << "\n";
    }
    return 0;
}
