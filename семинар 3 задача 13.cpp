#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<double> temp = { 150.0, 180.0, -150.0, 250.0, 170.0, 160.0, -50.0, 300.0 };

    cout << "До очистки: ";
    for (double t : temp) cout << t << " ";
    cout << "\n";

    auto new_end = remove_if(temp.begin(), temp.end(), [](double t) {
        return t < -100.0 || t > 200.0;  
        });
    temp.erase(new_end, temp.end());

    cout << "После очистки: ";
    for (double t : temp) cout << t << " ";
    cout << "\n";
    return 0;
}