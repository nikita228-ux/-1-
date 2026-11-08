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
    if(v0 <= 0.0) {
        cout << "Внимание: начальная скорость должна быть положительной!\n";
        return 1;
    }
    vector<double> times;
    vector<double> heights;
    
    int estimated_size = (int)(v0 * 2.0 / g / dt) + 1;
    times.reserve(estimated_size);
    heights.reserve(estimated_size);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            break;
        }
        times.push_back(t);
        heights.push_back(h);
    }
   if (heights.empty()){
       cout << "Данных нет! Вектор пуст\n";
       return 1;
   }
   size_t idx_max = 0;
   for (size_t i = 1; i < heights.size(); ++i) {
       if (heights[i] > heights[idx_max]) {
           idx_max = i;
       }
   }
   
    cout << fixed << setprecision(2);
    cout << "Задача1 Таблица:\n";
    cout << setw(10) << "время (с)" << "|" << setw(12) << "высота (м) " << "\n";


    for (size_t i = 0;i < times.size();++i) {
        cout << setw(10) << times[i] << "|" << setw(10) << heights[i] << "\n";
    }
    cout << "Задача 2 Результаты:\n";
    cout << "Максимальная высота:" << fixed << setprecision(2) << heights[idx_max] <<" м\n";
    cout << "Достигнута в момент:" << times[idx_max] << " c\n";
    return 0;
}
