#include <iostream>
using namespace std;
class FlightComputer {
    private:
        double altitude;  
        double velocity;  
        double fuel;     
        double thrust; 
public:
    FlightComputer(double alt,double vel,double fl, double thr): altitude(alt),velocity(vel),fuel(fl),thrust(thr){}
    void simulateStep(double dt) {
        velocity += (thrust / 1000.0 - 9.8) * dt;  
        altitude += velocity * dt;                  
        fuel -= dt * 2;                        
    }
    void printStatus(double time) const {
        cout << "t=" << time << "с: высота=" << altitude
            << "м, скорость=" << velocity << "м/с, топливо=" << fuel << "\n";
    }
};
int main() {
    setlocale(LC_ALL, "Ru");

    FlightComputer fc(0, 0, 100, 12000); 

    for (int i = 0; i < 5; i++) {
        double dt = 0.5;
        fc.simulateStep(dt);
        fc.printStatus((i + 1) * dt);
    }

    return 0;
}