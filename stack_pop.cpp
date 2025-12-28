#include <iostream>
using namespace std;

#define MAX 10

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void Push(int item)
    {
        if (top == MAX - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = item;
        cout << item << " is pushed" << endl;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int data = arr[top];
        top--;
        cout << data << " is popped" << endl;
    }

    void print()
    {
        if (top != -1)
        {
            cout << "\tStack contains: ";
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};

int main()
{
    Stack s;

    s.print();

    s.Push(100);
    s.print();

    s.Push(200);
    s.print();

    s.Push(300);
    s.print();

    s.Pop();
    s.print();

    s.Pop();
    s.print();

    s.Pop();
    s.print();

    return 0;
}
