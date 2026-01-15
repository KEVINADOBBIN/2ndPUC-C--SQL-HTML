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

        cout << x << " is inserted" << endl;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int x = q[first];
        first = (first + 1) % QUEUE_SIZE;
        count--;

        cout << x << " is deleted" << endl;
        return x;
    }

    void getSize() {
        if (count > 0) {
            cout << "Queue contains: ";
            for (int i = 0; i < count; i++) {
                cout << q[(first + i) % QUEUE_SIZE] << " ";
            }
            cout << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.getSize();

    q.enqueue(20);
    q.getSize();

    q.enqueue(30);
    q.getSize();

    q.dequeue();
    q.getSize();

    q.dequeue();
    q.getSize();

    q.dequeue();
    q.getSize();

    return 0;
}
