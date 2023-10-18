#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0, i;
    cout << "Enter The Number\n";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
        
    }
    cout << sum << endl;

    return 0;
}