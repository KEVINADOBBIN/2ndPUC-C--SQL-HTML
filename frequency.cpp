#include <iostream>
using namespace std;

class Frequency
{
private:
    int n, m[100], ele, freq;

public:
    void getdata();
    void findfreq();
    void display();
};

void Frequency::getdata()
{
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " elements into the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    cout << "Enter the search element: ";
    cin >> ele;
}

void Frequency::findfreq()
{
    freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i] == ele)
            freq++;
    }
}

void Frequency::display()
{
    if (freq > 0)
        cout << "Frequency of " << ele << " is " << freq << endl;
    else
        cout << ele << " does not exist" << endl;
}

int main()
{
    Frequency F;

    F.getdata();
    F.findfreq();
    F.display();

    return 0;
}
