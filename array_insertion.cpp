#include <iostream>
#include <iomanip>
using namespace std;

class Insertion {
private:
    int n;
    int m[100];
    int ele;
    int p;

public:
    void getData() {
        cout << "How many elements? ";
        cin >> n;

        cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        cout << "Enter the element to be inserted: ";
        cin >> ele;

        cout << "Enter the position (0 to " << n << "): ";
        cin >> p;
    }

    void insertElement() {
        if (p < 0 || p > n) {
            cout << p << " is an invalid position." << endl;
            return;
        }

        for (int i = n - 1; i >= p; i--) {
            m[i + 1] = m[i];
        }

        m[p] = ele;
        n = n + 1;

        cout << "Element is successfully inserted." << endl;
    }

    void display() {
        cout << "The array after insertion is:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(4) << m[i];
        }
        cout << endl;
    }
};

int main() {
    Insertion I;

    I.getData();
    I.insertElement();
    I.display();

    return 0;
}
