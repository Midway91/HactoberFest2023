#include <iostream>
using namespace std;
int main()
{
    int hour;
    cout << "Enter Hours\n";
    cin >> hour;
    if (hour <= 9 || hour >= 18)
    {
        cout << "Leisure";
    }
    else
    {
        cout << "Working";
    }
    return 0;
}