#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Point {
	double x;
	double y;
	double z;
};
int main() {
	setlocale(LC_ALL, "RU");

    const double vx = 30.0;
	const double vy = 20.0;
	const double vz = 40.0;
	const double dt = 1.0;
	const double t_max = 5.0;
	vector<Point> trajectory;
	trajectory.reserve((int)(t_max / dt) + 1);
		for (double t = 0.0; t <= t_max; t += dt) {
			Point p;
			p.x = vx * t;
			p.y = vy* t;
			p.z = vz * t;
			trajectory.push_back(p);
		}
	cout << fixed << setprecision(2);

	cout << setw(10) << "Время (с)"<< "|" << setw(10) << "X (м)"<< "|" << setw(10) << "Y (м)"<< "|" << setw(10) << "Z (м)" << "\n";
	
	for (size_t i = 0; i < trajectory.size(); ++i) {
		double t = i * dt;
	cout << setw(10) << t << "|" << setw(10) << trajectory[i].x<< "|" << setw(10) << trajectory[i].y<< "|" << setw(10) 
		<< trajectory[i].z << "\n";
	}
	return 0;
} { 5.0, 15.0, 8.0, 25.0, 2.0, 12.0, 9.0, 30.0 }
