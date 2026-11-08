﻿#include <iostream>
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
    vector<double> heights;
    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            break;
        }
        times.push_back(t);
        heights.push_back(h);
    }
    cout << fixed << setprecision(2);
    cout << setw(10) << "время (с)" << "|" << setw(12) << "высота (м) " << "\n";

    for (size_t i = 0;i < times.size();++i) {
        cout << setw(10) << times[i] << "|" << setw(10) << heights[i] << "\n";
    }
    return 0;
}
    
