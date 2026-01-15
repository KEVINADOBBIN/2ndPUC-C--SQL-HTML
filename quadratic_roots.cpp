#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
private:
    double a, b, c;
    double r1, r2;
    double d;

public:
    void getData() {
        cout << "Enter the coefficients a, b and c: ";
        cin >> a >> b >> c;
    }

    void compute() {
        d = b * b - 4 * a * c;

        if (d == 0) {
            cout << "Roots are real and equal." << endl;
            r1 = -b / (2 * a);
            r2 = r1;
        }
        else if (d > 0) {
            cout << "Roots are real and different." << endl;
            r1 = (-b + sqrt(d)) / (2 * a);
            r2 = (-b - sqrt(d)) / (2 * a);
        }
        else {
            cout << "Roots are imaginary." << endl;
        }
    }

    void putData() {
        if (d >= 0) {
            cout << "First root = " << r1 << endl;
            cout << "Second root = " << r2 << endl;
        }
    }
};

int main() {
    Quadratic q;

    q.getData();
    q.compute();
    q.putData();

    return 0;
}
