#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point {
    double x;
    double y;
};

class Rocket {
private:
    double x, y;
    double vx, vy;

public:
    Rocket(double x0, double y0, double vx0, double vy0)
        : x(x0), y(y0), vx(vx0), vy(vy0) {
    }

    void changeVelocity(double ax, double ay, double dt) {
        vx += ax * dt;
        vy += ay * dt;
    }

    void updatePosition(double dt) {
        x += vx * dt;
        y += vy * dt;
    }

    Point getPosition() const {
        return { x, y };
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(1100, 5, 10, 60);
    squad.emplace_back(1050, 20, -10, 45);
    squad.emplace_back(950, 0, 5, 55);

    const double T = 10.0;
    const double dt = 1.0;
    const int n = 5;

    vector<vector<Point>> trajectories(n);

    for (double t = 0.0; t <= T; t += dt) {
        for (int i = 0; i < n; ++i) {
            trajectories[i].push_back(squad[i].getPosition());
            squad[i].changeVelocity(0.0, -9.8, dt);
            squad[i].updatePosition(dt);
        }
    }

    cout << fixed << setprecision(2);
    cout << "Конечные положения ракет после " << T << " секунд:\n";
    for (int i = 0; i < n; ++i) {
        Point final_pos = squad[i].getPosition();
        cout << "Ракета " << i + 1 << ": x = " << final_pos.x
            << ", y = " << final_pos.y << "\n";
    }

    return 0;
}
