#include <iostream>
#include <cmath>
using namespace std;

struct Aircraft {
    double m;
    double T;
    double CL;
    double CD;
    double time; 
};

int main() {
    setlocale(LC_ALL, "RU");

    const double rho = 1.225;
    const double V = 100.0;
    const double S = 30.0;
    const double g = 9.81;

    double h;
    cout << "Введите высоту для набора h (м): ";
    cin >> h;

    
    Aircraft fleet[3] = {
        {10000, 50000, 1.2, 0.02, 0},
        {15000, 70000, 1.1, 0.03, 0},
        {8000,  40000, 1.3, 0.025, 0}
    };

    
    for (int i = 0; i < 3; i++) {
        double L = 0.5 * rho * V * V * S * fleet[i].CL;
        double D = 0.5 * rho * V * V * S * fleet[i].CD;
        double ay = (L - fleet[i].m * g) / fleet[i].m;

        if (ay > 0) {
            fleet[i].time = sqrt(2 * h / ay);
        }
        else {
            fleet[i].time = 1e9; 
        }
    }

    
    for (int i = 0; i < 2; i++) {           
        for (int j = 0; j < 2 - i; j++) {   
            
            if (fleet[j].time > fleet[j + 1].time) {
               
                Aircraft temp = fleet[j];       
                fleet[j] = fleet[j + 1];        
                fleet[j + 1] = temp;            
            }
        }
    }

    cout << "\n Рейтинг самолетов \n";
    for (int i = 0; i < 3; i++) {
        cout << "Место " << i + 1 << ": Самолет с массой " << fleet[i].m
            << " кг. Время набора высоты: " << fleet[i].time << " с\n";
    }

    return 0;
}
