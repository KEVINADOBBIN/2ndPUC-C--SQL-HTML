#include <iostream>
#include <iomanip>
using namespace std;

class Sorting {
private:
    int m[100];
    int n;

public:
    void getData() {
        cout << "How many elements? ";
        cin >> n;

        cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }
    }

    void sortArray() {
        int temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (m[j] > m[j + 1]) {
                    temp = m[j];
                    m[j] = m[j + 1];
                    m[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        cout << "The array after sorting in ascending order is:\n";
        for (int i = 0; i < n; i++) {
            cout << setw(4) << m[i];
        }
        cout << endl;
    }
};

int main() {
    Sorting S;

    S.getData();
    S.sortArray();
    S.display();

    return 0;
}
