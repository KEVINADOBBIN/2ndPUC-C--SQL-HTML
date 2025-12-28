#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int m[100];
    int n, ele, loc;

public:
    void getData();
    void search();
    void display();
};

void BinarySearch::getData()
{
    cout << "How many elements? ";
    cin >> n;

    cout << "Enter the elements (in sorted order): ";
    for (int i = 0; i < n; i++)
        cin >> m[i];

    cout << "Enter the search element: ";
    cin >> ele;
}

void BinarySearch::search()
{
    int beg = 0, end = n - 1, mid;
    loc = -1;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (ele == m[mid])
        {
            loc = mid;
            break;
        }
        else if (ele < m[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }
}

void BinarySearch::display()
{
    if (loc >= 0)
        cout << "Position = " << loc << endl;
    else
        cout << "Search is unsuccessful" << endl;
}

int main()
{
    BinarySearch B;
    B.getData();
    B.search();
    B.display();
    return 0;
}
