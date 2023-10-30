#include <iostream>
using namespace std;
int main()
{
    int n, m , p, rev = 0;
    cout<<"Enter The Number\n";
    cin>>n;
    m =n;
    while (m > 0)
    {
        p = m % 10;
        m = m / 10;
        rev = rev * 10 + p;
    }
    cout << rev<<endl;
    if(n == rev){
        cout<<"Its A Pallindrome";
    }
    return 0;
}