#include <iostream>
using namespace std;
int main()
{
    int n, p, rev = 0;
    cout<<"Enter The Number\n";
    cin>>n;
    while (n > 0)
    {
        p = n % 10;
        n = n / 10;
        rev = rev * 10 + p;
    }
    cout << rev;
    return 0;
}