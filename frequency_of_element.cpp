#include <iostream>
using namespace std;

class Frequency {
private:
    int n;
    int arr[100];
    int ele;
    int freq;

public:
    void getData() {
        cout << "Enter the size of the array: ";
        cin >> n;

        cout << "Enter " << n << " elements into the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the element to search: ";
        cin >> ele;
    }

    void findFrequency() {
        freq = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele) {
                freq++;
            }
        }
    }

    void display() {
        if (freq > 0) {
            cout << "Frequency of " << ele << " is " << freq << endl;
        } else {
            cout << ele << " does not exist in the array." << endl;
        }
    }
};

int main() {
    Frequency f;

    f.getData();
    f.findFrequency();
    f.display();

    return 0;
}
