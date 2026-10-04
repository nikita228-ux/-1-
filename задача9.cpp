#include <iostream>
using namespace std;

struct Aircraft {
    double m, S, T, CL, CD;
    double acc;
};

int main() {
    setlocale(LC_ALL, "RU");

    int N;
    cout << "Введите количество самолетов N: ";
    cin >> N;

    Aircraft* fleet = new Aircraft[N];

    const double rho = 1.225;
    const double V = 100.0;

    double max_acc = -1e9;
    int leader_idx = 0;    

    for (int i = 0; i < N; i++) {
        cout << "\nСамолет " << i + 1 << ":\n";
        cout << "  Масса m (кг): "; cin >> fleet[i].m;
        cout << "  Площадь крыла S (м^2): "; cin >> fleet[i].S;
        cout << "  Тяга T (Н): "; cin >> fleet[i].T;
        cout << "  Коэф. подъемной силы CL: "; cin >> fleet[i].CL;
        cout << "  Коэф. сопротивления CD: "; cin >> fleet[i].CD;

        double L = 0.5 * rho * V * V * fleet[i].S * fleet[i].CL;
        double D = 0.5 * rho * V * V * fleet[i].S * fleet[i].CD;

        fleet[i].acc = (fleet[i].T - D) / fleet[i].m;

        cout << "  Подъемная сила L = " << L << " Н\n";
        cout << "   Сопротивление D = " << D << " Н\n";
        cout << "  Ускорение a = " << fleet[i].acc << " м/с^2\n";

        
        if (fleet[i].acc > max_acc) {
            max_acc = fleet[i].acc;
            leader_idx = i;
        }
    }
    cout << "\nИтог:\n";
    cout << "Самолет с наибольшим ускорением: номер " << leader_idx + 1 << endl;
    cout << "Его ускорение: " << max_acc << " м/с^2" << endl;

    delete[] fleet;

    return 0;
}