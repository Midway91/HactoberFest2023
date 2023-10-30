#include <iostream>
using namespace std;
int power(int a, int b)
{
    int result = 1;
    for (int i = 1; i <= b; i++)
    {
        result *= a;
    }
    return result;
}
int main()
{
    int a = 2 , b = 3;
    int z = power(a , b);
    cout<<"Result Is "<<z;

    return 0;
}