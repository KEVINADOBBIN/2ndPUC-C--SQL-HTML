#include <iostream>
using namespace std;

class Student {
private:
    int regno;
    char name[20];
    float fees;

public:
    void get() {
        cout << "Enter student registration number: ";
        cin >> regno;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student fees: ";
        cin >> fees;
    }

    void display() {
        cout << "\nStudent registration number: " << regno << endl;
        cout << "Student name: " << name << endl;
        cout << "Student fees: " << fees << endl;
    }
};

int main() {
    Student s;
    Student *sp;

    sp = &s;          // pointer to object

    sp->get();        // accessing using pointer
    sp->display();

    return 0;
}
