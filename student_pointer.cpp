#include <iostream>
using namespace std;

class Student {
private:
    int regno;
    char name[20];
    float fees;

public:
    void get() {
        cout << "Enter student register number: ";
        cin >> regno;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student fees: ";
        cin >> fees;
    }

    void display() {
        cout << "\nStudent Register Number: " << regno << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Fees: " << fees << endl;
    }
};

int main() {
    Student s;
    Student *ptr;

    ptr = &s;   // pointer to object

    ptr->get();       // accessing members using pointer
    ptr->display();

    return 0;
}
