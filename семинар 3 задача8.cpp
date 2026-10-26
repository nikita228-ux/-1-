#include <iostream>      
#include <vector>        
#include <algorithm>     
#include <iomanip>       
using namespace std;

vector<double> fillTrajectory(double v0, double g, double dt, vector<double>& times) {
    vector<double> heights;
    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (h < 0.0) {
            break;
        }
    }
    return heights;
}

double findFallTime(const vector<double>& heights, const vector<double>& times, double dt) {
    auto it = find_if(heights.begin(), heights.end(), [](double h) {
        return h < 0.0;
        });
    if (it == heights.end()) {
        return -1.0; 
    }
    size_t idx = distance(heights.begin(), it);
    return times[idx];
}

int main() {
    setlocale(LC_ALL, "RU");

    const double g = 9.8;
    const double dt = 1.0;

    vector<double> times1;
    vector<double> heights1 = fillTrajectory(50.0, g, dt, times1);

    vector<double> times2;
    vector<double> heights2 = fillTrajectory(70.0, g, dt, times2);

    auto max_it1 = max_element(heights1.begin(), heights1.end());
    double max_h1 = *max_it1;
    size_t idx_max1 = distance(heights1.begin(), max_it1);
    double t_max1 = times1[idx_max1];
    double t_fall1 = findFallTime(heights1, times1, dt);

    auto max_it2 = max_element(heights2.begin(), heights2.end());
    double max_h2 = *max_it2;
    size_t idx_max2 = distance(heights2.begin(), max_it2);
    double t_max2 = times2[idx_max2];
    double t_fall2 = findFallTime(heights2, times2, dt);

    double print_fall1;
    if (t_fall1 >= 0) {
        print_fall1 = t_fall1;
    }
    else {
        print_fall1 = -1.0;
    }

    double print_fall2;
    if (t_fall2 >= 0) {
        print_fall2 = t_fall2;
    }
    else {
        print_fall2 = -1.0;
    }
  
    cout << fixed << setprecision(2);
    cout << " Сравнение траекторий: \n";
    cout << setw(28) << "Параметр" << "|" << setw(12) << "Ракета 1" << "|" << setw(12) << "Ракета 2" << "\n";
    cout << setw(28) << "Начальная скорость (м/с)" << "|" << setw(12) << "50.00" << "|" << setw(12) << "70.00" << "\n";
    cout << setw(28) << "Максимальная высота (м)" << "|" << setw(12) << max_h1 << "|" << setw(12) << max_h2 << "\n";
    cout << setw(28) << "Время достижения макс. (с)" << "|" << setw(12) << t_max1 << "|" << setw(12) << t_max2 << "\n";
    cout << setw(28) << "Момент падения (с)" << "|" << setw(12) << print_fall1 << "|" << setw(12) << print_fall2 << "\n";

   
    cout << " Результаты:\n";
    if (max_h1 > max_h2) {
        cout << "Ракета 1 поднялась выше (" << max_h1 << " м > " << max_h2 << " м)\n";
    }
    else if (max_h2 > max_h1) {
        cout << "Ракета 2 поднялась выше (" << max_h2 << " м > " << max_h1 << " м)\n";
    }
    else {
        cout << "Ракеты поднялись на одинаковую высоту\n";
    }

    if (t_fall1 > t_fall2 && t_fall1 >= 0) {
        cout << "Ракета 1 дольше в воздухе (" << t_fall1 << " с > " << t_fall2 << " с)\n";
    }
    else if (t_fall2 > t_fall1 && t_fall2 >= 0) {
        cout << "Ракета 2 дольше в воздухе (" << t_fall2 << " с > " << t_fall1 << " с)\n";
    }
    else {
        cout << "Ракеты находились в воздухе одинаковое время (или данные отсутствуют)\n";
    }

    return 0;
}