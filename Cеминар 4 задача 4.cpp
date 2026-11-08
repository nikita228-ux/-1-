#include <iostream>
using namespace std;
class Gyroscope {
private:
    double angularVelocity;        
    bool calibrationRequired; 
public:
    Gyroscope(double v, bool cal): angularVelocity(v), calibrationRequired(cal) {}
    void calibrate() {
        calibrationRequired = false; 
    }
    void printStatus() const {
        cout << "Скорость: " << angularVelocity << " °/с | ";
        if (calibrationRequired) {
            cout << "Калибровка требуется\n";
        }
        else {
            cout << "Калибровка не требуется\n";
        }
    }
        };
        int main() {
            setlocale(LC_ALL, "Ru");

            Gyroscope g1(120.5, true);  

            g1.printStatus();         
            g1.calibrate();         
            g1.printStatus();           

            return 0;
        }
  