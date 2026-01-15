#include <iostream>
using namespace std;

class PowerSeries {
private:
    int x, n;

public:
    // Constructor
    PowerSeries(int xx, int nn) {
        x = xx;
        n = nn;
    }

    int calculate() {
        int sum = 1;   // first term is 1
        int term = 1;

        for (int i = 1; i <= n; i++) {
            term = term * x;
            sum = sum + term;
        }

        return sum;
    }
};

int main() {
    int x, n;

    cout << "Enter the base (x) and the power (n): ";
    cin >> x >> n;

    PowerSeries obj(x, n);

    cout << "Sum of the series = " << obj.calculate() << endl;

    return 0;
}
