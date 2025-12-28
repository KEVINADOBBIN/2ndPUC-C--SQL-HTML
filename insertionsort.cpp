#include <iostream>
#include <iomanip>
using namespace std;

class Sorting
{
private:
    int m[100];
    int n;

public:
    void getData();
    void sortArray();
    void display();
};

void Sorting::getData()
{
    cout << "How many elements? ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> m[i];
}

void Sorting::sortArray()
{
    int temp, j;

    for (int i = 1; i < n; i++)
    {
        temp = m[i];
        j = i - 1;

        while (j >= 0 && m[j] > temp)
        {
            m[j + 1] = m[j];
            j--;
        }
        m[j + 1] = temp;
    }
}

void Sorting::display()
{
    cout << "The array after sorting is: ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << m[i];
    cout << endl;
}

int main()
{
    Sorting S;
    S.getData();
    S.sortArray();
    S.display();
    return 0;
}
