#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout <<" Тест 1: Смешанные значения: \n";
    vector<double> heights = { 5.0, 15.0, 8.0, 25.0, 2.0, 12.0, 9.0, 30.0 };

    cout << "Исходный вектор высот:\n";
    for (double h : heights) {
        cout << h << " ";
    }
    cout << "\n";

    auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {
        return h < 10.0;
        });
    heights.erase(new_end, heights.end());

    cout << "Вектор после удаления значений <10 м:\n";
    for (double h : heights) {
        cout << h << " ";
    }
    cout << "\n";

    cout << " Тест 2: Все значения < 10 :\n";
    vector<double> heights2 = { 1.0, 5.0, 8.0, 3.0, 9.0 };

    cout << "Исходный вектор высот:\n";
    for (double h : heights2) {
        cout << h << " ";
    }
    cout << "\n";

    auto new_end2 = remove_if(heights2.begin(), heights2.end(), [](double h) {
        return h < 10.0;
        });
    heights2.erase(new_end2, heights2.end());

    cout << "Вектор после удаления значений <10 м:\n";
    if (heights2.empty()) {
        cout << "(вектор пуст)";
    }
    else {
        for (double h : heights2) {
            cout << h << " ";
        }
    }
    cout << "\n";

    cout << " Тест 3: Все значения >= 10 \n";
    vector<double> heights3 = { 10.0, 15.0, 20.0, 25.0, 30.0 };

    cout << "Исходный вектор высот:\n";
    for (double h : heights3) {
        cout << h << " ";
    }
    cout << "\n";

    auto new_end3 = remove_if(heights3.begin(), heights3.end(), [](double h) {
        return h < 10.0;
        });
    heights3.erase(new_end3, heights3.end());
    cout << "Вектор после удаления значений <10 м:\n";
    for (double h : heights3) {
        cout << h << " ";
    }
    cout << "\n";
    return 0;
}