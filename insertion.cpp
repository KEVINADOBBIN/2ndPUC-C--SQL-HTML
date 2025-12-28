#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Insertion
{
private:
    int n, m[100], ele, p;

public:
    void getdata();
    void insert();
    void display();
};

void Insertion::getdata()
{
    cout << "How many elements? ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> m[i];

    cout << "Enter the element to be inserted: ";
    cin >> ele;

    cout << "Enter the position (0 to " << n << "): ";
    cin >> p;
}

void Insertion::insert()
{
    if (p < 0 || p > n)
    {
        cout << p << " is an invalid position" << endl;
        exit(0);
    }

    for (int i = n - 1; i >= p; i--)
        m[i + 1] = m[i];

    m[p] = ele;
    n = n + 1;

    cout << ele << " is successfully inserted into position " << p << endl;
}

void Insertion::display()
{
    cout << "The array after the insertion is\n";
    for (int i = 0; i < n; i++)
        cout << setw(4) << m[i];
    cout << endl;
}

int main()
{
    Insertion I;

    I.getdata();
    I.insert();
    I.display();

    return 0;
}
