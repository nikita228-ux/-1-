#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<double> sensor = { 9.8, 9.7, 0.0, 9.9, 0.0, 0.0, 9.8, 0.0, 9.6 };

    cout << "Данные датчика: ";
    for (double v : sensor) cout << v << " ";
    cout << "\n";

    int zero_count = count(sensor.begin(), sensor.end(), 0.0);

    cout << "Количество нулевых показаний: " << zero_count << "\n";
    cout << "Всего измерений: " << sensor.size() << "\n";
    cout << "Рабочих измерений: " << sensor.size() - zero_count << "\n";

    return 0;
}