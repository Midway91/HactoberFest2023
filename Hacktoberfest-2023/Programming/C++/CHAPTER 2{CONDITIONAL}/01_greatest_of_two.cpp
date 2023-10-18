#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter Two Numbers\n";
    cin >> x >> y;
    if (x > y)
    {
        cout << "max is "<<x<<"\n";
    }
    else
    {
        cout << "max is "<<y<<"\n";
    }
    return 0;
}