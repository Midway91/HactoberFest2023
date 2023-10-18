#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int p, n, m , sum = 0;
    cout << "Enter The Number\n";
    cin >> n;
    m = n;
    while (m > 0)
    {
        p = m % 10;
        sum = sum + p*p*p;
        m = m /= 10;
    }
    cout<<sum<<endl;
    if (sum == n)
    {
        cout << "Its A Reynolds Number";
    }
    else{
        cout<<"Its not a reynolds number";
    }
    return 0;
}