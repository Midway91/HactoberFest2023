#include <iostream>
using namespace std;
int main()
{
    int p, n;
    cout << "Enter The Number\n";
    cin >> n;
    while (n > 0)
    {
        p = n % 10;
        cout << p<< endl;
        n = n / 10;
    }
    return 0;
}