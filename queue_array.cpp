#include <iostream>
using namespace std;

#define QUEUE_SIZE 100

class Queue {
private:
    int q[QUEUE_SIZE];
    int first, last;
    int count;

public:
    Queue() {
        first = 0;
        last = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == QUEUE_SIZE) {
            cout << "Queue is full" << endl;
            return;
        }

        last = (last + 1) % QUEUE_SIZE;
        q[last] = x;
        count++;

        cout << x << " inserted into queue" << endl;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int item = q[first];
        first = (first + 1) % QUEUE_SIZE;
        count--;

        return item;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << q[(first + i) % QUEUE_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            value = q.dequeue();
            if (value != -1)
                cout << "Deleted element: " << value << endl;
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
