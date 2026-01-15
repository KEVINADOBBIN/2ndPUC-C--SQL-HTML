#include <iostream>
using namespace std;

// Inline function
inline int cube(int a) {
    return a * a * a;
}

int main() {
    int x, y;

    cout << "Enter a number: ";
    cin >> x;

    y = cube(x);

    cout << "Cube of " << x << " = " << y << endl;

    return 0;
}
