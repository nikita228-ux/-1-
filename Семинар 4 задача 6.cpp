#include <iostream>
using namespace std;
class RocketStage {
private:
    double thrust;
    double burnTime;
    double mass;
public:
    RocketStage(double T, double t, double m) : thrust(T), burnTime(t), mass(m) {}
    double getDeltaV() const {
        return (thrust * burnTime) / mass;
    }
    void printInfo() const {
        cout << "Ступень: тяга=" << thrust << " Н, время=" << burnTime << " с, масса=" << mass << " кг, дельтаV=" << getDeltaV() << " м/с\n";
    }
};
int main() {
    setlocale(LC_ALL, "Russian");

    RocketStage s1(5000, 10, 1000);  
    RocketStage s2(7000, 8, 900);    
    RocketStage s3(9000, 6, 800);    

    s1.printInfo();
    s2.printInfo();
    s3.printInfo();

    double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();
    cout << "Итоговая скорость ракеты: " << totalV << " м/с\n";

    return 0;
}