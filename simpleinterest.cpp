#include <iostream>
#include <iomanip>
using namespace std;

class Interest
{
private:
    double p, t, r, si;

public:
    void getData();
    void compute();
    void putData();
};

void Interest::getData()
{
    cout << "Enter principle amount, time and rate:" << endl;
    cin >> p >> t >> r;
}

void Interest::compute()
{
    si = (p * t * r) / 100;
}

void Interest::putData()
{
    cout << fixed << setprecision(2);
    cout << "Principle: " << p << endl;
    cout << "Time: " << t << endl;
    cout << "Rate: " << r << endl;
    cout << "Simple Interest: " << si << endl;
}

int main()
{
    Interest o;
    o.getData();
    o.compute();
    o.putData();
    return 0;
}