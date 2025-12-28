#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class FunOverload
{
private:
    double s;

public:
    // Area of square
    double area(double a)
    {
        return a * a;
    }

    // Area of rectangle
    double area(double l, double b)
    {
        return l * b;
    }

    // Area of triangle (Heron's formula)
    double area(double a, double b, double c)
    {
        s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main()
{
    FunOverload f;
    double x, y, z;
    int ans;

    cout << "Enter the number of inputs (1, 2 and 3): ";
    cin >> ans;

    if (ans == 1)
    {
        cout << "Enter the side: ";
        cin >> x;
        cout << "Area of the square = " << f.area(x) << endl;
    }
    else if (ans == 2)
    {
        cout << "Enter two sides: ";
        cin >> x >> y;
        cout << "Area of the rectangle = " << f.area(x, y) << endl;
    }
    else if (ans == 3)
    {
        cout << "Enter three sides: ";
        cin >> x >> y >> z;
        cout << fixed << setprecision(5);
        cout << "Area of the triangle = " << f.area(x, y, z) << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 0;
}
