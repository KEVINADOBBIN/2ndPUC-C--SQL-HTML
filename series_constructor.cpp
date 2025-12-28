#include <iostream>
using namespace std;

class Series
{
private:
    int x, n;

public:
    Series(int xx, int nn)
    {
        x = xx;
        n = nn;
    }

    int calculate()
    {
        int sum = 1;        // First term = 1
        int nextTerm = x;   // Start with x

        for (int i = 1; i <= n; i++)
        {
            sum += nextTerm;
            nextTerm *= x;  // Compute next power of x
        }

        return sum;
    }
};

int main()
{
    int x, n;
    cout << "Enter the base and the power (x and n): ";
    cin >> x >> n;

    Series obj(x, n);
    Series cpy = obj;  // Copy constructor

    cout << "Object1: Sum of the series = " << obj.calculate() << endl;
    cout << "Object2: Sum of the series = " << cpy.calculate() << endl;

    return 0;
}
