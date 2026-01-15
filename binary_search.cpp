#include <iostream>
using namespace std;

class BinarySearch {
private:
    int m[100];
    int n;
    int ele;
    int loc;

public:
    void getData() {
        cout << "How many elements? ";
        cin >> n;

        cout << "Enter the elements in ascending order:\n";
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        cout << "Enter the element to search: ";
        cin >> ele;
    }

    void search() {
        int beg = 0;
        int end = n - 1;
        int mid;
        loc = -1;

        while (beg <= end) {
            mid = (beg + end) / 2;

            if (m[mid] == ele) {
                loc = mid;
                break;
            } else if (ele < m[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
    }

    void display() {
        if (loc >= 0) {
            cout << "Search successful.\n";
            cout << "Element found at position: " << loc << endl;
        } else {
            cout << "Search is unsuccessful." << endl;
        }
    }
};

int main() {
    BinarySearch B;

    B.getData();
    B.search();
    B.display();

    return 0;
}
