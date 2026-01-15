#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class FunctionOverload {
public:
    // Area of square
    double area(double a) {
        return a * a;
    }

    // Area of rectangle
    double area(double l, double b) {
        return l * b;
    }

    // Area of triangle (Heron's formula)
    double area(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    FunctionOverload f;
    int choice;
    double x, y, z;

    cout << "Enter the number of inputs (1 / 2 / 3): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    if (choice == 1) {
        cout << "Enter the side of the square: ";
        cin >> x;
        cout << "Area of the square = " << f.area(x) << endl;
    }
    else if (choice == 2) {
        cout << "Enter the length and breadth of the rectangle: ";
        cin >> x >> y;
        cout << "Area of the rectangle = " << f.area(x, y) << endl;
    }
    else if (choice == 3) {
        cout << "Enter the three sides of the triangle: ";
        cin >> x >> y >> z;
        cout << "Area of the triangle = " << f.area(x, y, z) << endl;
    }
    else {
        cout << "Invalid input." << endl;
    }

    return 0;
}
