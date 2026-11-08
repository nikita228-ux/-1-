#include <iostream>
#include <cmath>
using namespace std;

struct Aircraft {
    double m;  
    double S;   
    double T;   
    double CL;  
    double CD;  
};

int main() {
    setlocale(LC_ALL, "RU");

    const double ro = 1.225; 
    const double V = 100.0;   
    const double g = 9.81;  

    double h;
    cout << "Введите высоту для набора h (м): ";
    cin >> h;

    Aircraft planes[3] = {
        {10000, 30, 50000, 1.2, 0.02},   
        {15000, 40, 70000, 1.1, 0.03},   
        {8000,  25, 40000, 1.3, 0.025}   
    };

    int bestIdx = -1;       
    double minTime = 1e9;   

    cout << "Результаты расчетов:\n";

    for (int i = 0; i < 3; i++) {
       
        double L = 0.5 * ro * V * V * planes[i].S * planes[i].CL;
        double D = 0.5 * ro * V * V * planes[i].S * planes[i].CD;
        double ay = (L - planes[i].m * g) / planes[i].m;

        cout << "Самолет " << i + 1 << ": ";
        cout << "Подъемная сила L = " << L << " Н, ";
        cout << "Сопротивление D = " << D << " Н, ";
        cout << "Вертик. ускорение ay = " << ay << " м/с^2\n";

        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            cout << " Время набора высоты: " << t << " с\n";

            
            if (t < minTime) {
                minTime = t;
                bestIdx = i;
            }
        }
        else {
            cout << " Не может набрать высоту (ay <= 0)!\n";
        }
    }
     
    cout << " Итог:\n";
    if (bestIdx != -1) {
        cout << "Быстрее всех высоту " << h << " м наберет Самолет номер " << bestIdx + 1 << endl;
        cout << "Его время: " << minTime << " с" << endl;
    }
    else {
        cout << "Ни один самолет не способен набрать эту высоту." << endl;
    }

    return 0;
}
