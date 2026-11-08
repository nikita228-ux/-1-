#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");

	const double v0 = 50.0;
	const double g = 9.8;
	const double dt = 1.0;

	vector<double> times;
	vector<double> heights;

	for (double t = 0.0;;t += dt) {
		double h = v0 * t - 0.5 * g * t * t;

		times.push_back(t);
		heights.push_back(h);

		if (h < 0.0) {
			break;
		}
	}
		cout << fixed << setprecision(2);
		cout << setw(10) << "Время (с)" << "|" << setw(10) << "Высота (м)" << "\n";
		for (size_t i = 0; i < times.size(); ++i) {
			cout << setw(10) << times[i] << "|" << setw(12) << heights[i] << "\n";
		}
		cout << "Момент падения:\n";

		auto it = find_if(heights.begin(), heights.end(), [](double h) {return h < 0.0;
			});
		if (it == heights.end()) {
			cout << "Падения не было в данном диапозоне\n";
		}
		else {
			size_t idx = distance(heights.begin(), it);
			cout << "Момент падения: t=" << times[idx] << " c\n";
			cout << "Высота в этот момент h=" << heights[idx] << " м\n";
			cout << "Индекс элемента: " << idx << "\n";
		}
		return 0;
	}
