#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	double S, V, ro, CL;
	cout << "Введите площадь крыла S (м^2):";
	cin >> S;

	cout << "Введите скорость полета  V (м/с):";
	cin >> V;

	cout << "Введите плотность воздуха ro (кг/м^3):";
	cin >> ro;

	cout << "Введите коэффициент подъёмной силы CL :";
	cin >> CL;

	double L = 0.5 * ro * V * V * S * CL;

	cout << " Подъёмная сила L = " << L << " Н " << endl;
	return 0;
}