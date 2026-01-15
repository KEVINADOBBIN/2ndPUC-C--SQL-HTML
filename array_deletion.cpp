#include <iostream>
#include <iomanip>
using namespace std;

class Deletion {
private:
    int m[100];
    int n;
    int p;
    int ele;

public:
    void getData() {
        cout << "How many elements? ";
        cin >> n;

        cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        cout << "Enter the position (0 to " << n - 1 << "): ";
        cin >> p;
    }

    void removeElement() {
        if (p < 0 || p > n - 1) {
            cout << p << " is an invalid position." << endl;
            return;
        }

        ele = m[p];

        for (int i = p; i < n - 1; i++) {
            m[i] = m[i + 1];
        }

        n = n - 1;

        cout << "The element " << ele << " at position "
             << p << " is successfully removed." << endl;
    }

    void display() {
        cout << "The array after deletion is:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(4) << m[i];
        }
        cout << endl;
    }
};

int main() {
    Deletion D;

    D.getData();
    D.removeElement();
    D.display();

    return 0;
}
