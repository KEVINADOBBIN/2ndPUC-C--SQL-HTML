#include <iostream>
#include <cmath>
using namespace std;

class Quadratic
{
private:
    double a, b, c, r1, r2, d;

public:
    void getData();
    void compute();
    void putData();
};

void Quadratic::getData()
{
    cout << "Enter the coefficients: ";
    cin >> a >> b >> c;
}

void Quadratic::compute()
{
    d = b * b - 4 * a * c;

    if (d == 0)
    {
        cout << "Roots are equal" << endl;
        r1 = r2 = -b / (2 * a);
    }
    else if (d > 0)
    {
        cout << "Roots are real and different" << endl;
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
    }
    else
    {
        cout << "Roots are imaginary" << endl;
        exit(0);
    }
}

void Quadratic::putData()
{
    cout << "First root = " << r1 << endl;
    cout << "Second root = " << r2 << endl;
}

int main()
{
    Quadratic q;
    q.getData();
    q.compute();
    q.putData();
    return 0;
}
