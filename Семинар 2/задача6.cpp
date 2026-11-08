#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const double S = 30.0;
    const double CL = 1.2;

    const int N = 5;

    
    double V[N] = { 100.0, 120.0, 140.0, 160.0, 180.0 };
    double ro[N] = { 1.225, 1.150, 1.050, 0.950, 0.850 };

    cout << fixed << setprecision(2);

   
    cout << "| " << setw(4) << "Шаг" << " | "
        << setw(8) << "Скорость" << " | "
        << setw(9) << "Плотность" << " | "
        << setw(14) << "Подъемная сила" << " |" << endl;

    for (int i = 0; i < N; i++) {
       
        double L = 0.5 * ro[i] * V[i] * V[i] * S * CL;

        cout << "| " << setw(4) << i + 1 << " | "
            << setw(8) << V[i] << " | "
            << setw(9) << ro[i] << " | "
            << setw(14) << L << " |" << endl;
    }
    return 0;
}
