#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double m, S, CL, CD, h;
   ;
    cout << "Введите массу самолета m (кг): ";
    cin >> m;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите коэффициент подъемной силы CL: ";
    cin >> CL;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;
    cout << "Введите целевую высоту h (м): ";
    cin >> h;

    
    double Tmin, Tmax, dT;
    cout << "\nВведите минимальную тягу Tmin (Н): ";
    cin >> Tmin;
    cout << "Введите максимальную тягу Tmax (Н): ";
    cin >> Tmax;
    cout << "Введите шаг изменения тяги dT (Н): ";
    cin >> dT;

  
    const double ro = 1.225;
    const double V = 100.0;
    const double g = 9.81;

    double L = 0.5 * ro * V * V * S * CL;
    double D = 0.5 * ro * V * V * S * CD;

    double bestT = Tmin;      
    double minTime = 1e9;    

    cout << fixed << setprecision(2);

    cout << "\n| " << setw(10) << "Тяга T" << " | "
        << setw(12) << "Ускор. ay" << " | "
        << setw(10) << "Время t" << " |\n";
   

    
    for (double T = Tmin; T <= Tmax; T += dT) {

        double ay = (L + T - m * g) / m;

        cout << "| " << setw(10) << T << " | "
            << setw(12) << ay << " | ";

        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            cout << setw(10) << t << " |\n";
      
            if (t < minTime) {
                minTime = t;
                bestT = T;
            }
        }
        else {
            
            cout << setw(10) << "---" << " |\n";
        }
    }
  
    cout << " Результат:\n";
    if (minTime < 1e9) {
        cout << "Оптимальная тяга: " << bestT << " Н\n";
        cout << "Минимальное время набора высоты " << h << " м: " << minTime << " с\n";
    }
    else {
        cout << "Ни одно значение тяги из заданного диапазона не позволяет набрать высоту.\n";
    }

    return 0;
}
