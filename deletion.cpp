#include <iostream>
#include <iomanip>
using namespace std;

class Deletion
{
private:
    int m[100];
    int n, p, ele;

public:
    void getData();
    void removeElement();
    void display();
};

void Deletion::getData()
{
    cout << "How many elements? ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> m[i];

    cout << "Enter the position (0 to " << n - 1 << "): ";
    cin >> p;
}

void Deletion::removeElement()
{
    if (p < 0 || p >= n)
    {
        cout << p << " is an invalid position" << endl;
        return;
    }

    ele = m[p];

    for (int i = p; i < n - 1; i++)
        m[i] = m[i + 1];

    n--;

    cout << "The element " << ele << " at position " << p
         << " is successfully removed" << endl;
}

void Deletion::display()
{
    cout << "The array after deletion is: ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << m[i];
    cout << endl;
}

int main()
{
    Deletion D;
    D.getData();
    D.removeElement();
    D.display();
    return 0;
}
