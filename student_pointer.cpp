#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int regNo;
    string name;
    float fees;

public:
    void get()
    {
        cout << "Enter student register number: ";
        cin >> regNo;
        cin.ignore(); // Clear newline from buffer
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student fees: ";
        cin >> fees;
    }

    void display()
    {
        cout << "Student register number: " << regNo << endl;
        cout << "Student name: " << name << endl;
        cout << "Student fees: " << fees << endl;
    }
};

int main()
{
    Student s;
    Student* sp = &s; // Pointer to object

    sp->get();       // Access member function using pointer
    sp->display();   // Access member function using pointer

    return 0;
}
