#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<double> x_coords = { 150.0, 100.0, 150.0, 200.0, 100.0, 250.0, 200.0, 150.0 };

    cout << "До обработки: ";
    for (double x : x_coords) cout << x << " ";
    cout << "\n";

    sort(x_coords.begin(), x_coords.end());

    cout << "После сортировки: ";
    for (double x : x_coords) cout << x << " ";
    cout << "\n";

    auto new_end = unique(x_coords.begin(), x_coords.end());
    x_coords.erase(new_end, x_coords.end());

    cout << "После удаления дубликатов: ";
    for (double x : x_coords) cout << x << " ";
    cout << "\n";

    return 0;
}