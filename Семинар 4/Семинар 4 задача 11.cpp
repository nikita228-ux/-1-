#include <iostream>
#include <iomanip>
using namespace std;

class Engine {
private:
    double thrust;    
    double fuelFlow;   
    double fuel;       

public:
    Engine(double T, double F, double fl)
        : thrust(T), fuelFlow(F), fuel(fl) {
    }

    double getThrust() const {
        return thrust;
    }

    double getFuel() const {
        return fuel;
    }

    bool hasFuel() const {
        return fuel > 0;
    }

    void burn(double dt) {
        if (fuel > 0) {
            fuel -= fuelFlow * dt;
            if (fuel < 0) fuel = 0;
        }
    }
};
class Navigation {
private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;

public:
    Navigation(double alt, double vel, double m)
        : altitude(alt), velocity(vel), mass(m), acceleration(0) {
    }

    void update(double thrust, double dt) {
        acceleration = thrust / mass - 9.81;
        velocity += acceleration * dt;
        altitude += velocity * dt;
    }

    void printStatus(double time) const {
        cout << fixed << setprecision(2);
        cout << "t=" << time << "с | h=" << altitude
            << "м | v=" << velocity << "м/с | a=" << acceleration << "м/с²\n";
    }
};
class AutonomousFlightSystem {
private:
    Engine engine;
    Navigation nav;
    double time;

public:
    AutonomousFlightSystem(const Engine& e, const Navigation& n)
        : engine(e), nav(n), time(0) {
    }

    void simulate(double dt, double totalTime) {
        while (time < totalTime && engine.hasFuel()) {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
        cout << "\n--- Полет завершен ---\n";
    }

    void printSummary() const {
        cout << "Оставшееся топливо: " << engine.getFuel() << " кг\n";
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Engine engine(20000, 10, 100);
    Navigation nav(0, 0, 1000);
    AutonomousFlightSystem afs(engine, nav);
    afs.simulate(1.0, 10.0);
    afs.printSummary();

    return 0;
}
