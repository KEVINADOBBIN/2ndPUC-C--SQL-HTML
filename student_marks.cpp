#include <iostream>
#include <string>
using namespace std;

// Base class
class Student
{
protected:
    int rollNo;
    string name;

public:
    void read()
    {
        cout << "Enter Roll No. and Name: ";
        cin >> rollNo >> ws; // ws to consume whitespace
        getline(cin, name);
    }

    void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

// Derived class
class Marks : public Student
{
private:
    int m1, m2, total;

public:
    void readMarks()
    {
        cout << "Enter two subject marks: ";
        cin >> m1 >> m2;
        total = m1 + m2;
    }

    void displayMarks()
    {
        cout << "Subject1 = " << m1 << endl;
        cout << "Subject2 = " << m2 << endl;
        cout << "Total marks = " << total << endl;
    }
};

int main()
{
    Marks ob;

    ob.read();
    ob.readMarks();
    ob.display();
    ob.displayMarks();

    return 0;
}
