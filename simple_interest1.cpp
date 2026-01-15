#include <iostream>
#include <iomanip>

using namespace std;

class Interest {
private:
    double p;   // principal
    double t;   // time
    double r;   // rate
    double si;  // simple interest

public:
    void getData() {
        cout << "Enter Principal Amount: ";
        cin >> p;

        cout << "Enter Time (in years): ";
        cin >> t;

        cout << "Enter Rate of Interest: ";
        cin >> r;
    }

    void compute() {
        si = (p * t * r) / 100;
    }

    void putData() {
        cout << fixed << setprecision(2);
        cout << "\nPrincipal: " << p;
        cout << "\nTime: " << t;
        cout << "\nRate: " << r;
        cout << "\nSimple Interest: " << si << endl;
    }
};

int main() {
    Interest obj;

    obj.getData();
    obj.compute();
    obj.putData();

    return 0;
}
