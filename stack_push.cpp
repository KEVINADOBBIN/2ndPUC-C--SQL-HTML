#include <iostream>
#include <cctype>
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
    char choice;
    int itm;

    s.print();

    cout << "Do you want to push an item (Y/N)? ";
    cin >> choice;

    while (toupper(choice) == 'Y')
    {
        cout << "Enter the item: ";
        cin >> itm;

        s.Push(itm);
        s.print();

        cout << "Do you want to push another item (Y/N)? ";
        cin >> choice;
    }

    return 0;
}
