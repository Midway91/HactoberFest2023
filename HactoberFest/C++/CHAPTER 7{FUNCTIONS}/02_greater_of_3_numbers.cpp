#include <iostream>
using namespace std;
int great(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else if (b > a)
    {
        if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}
int main()

{
    int a = 7 , b = 2 , c = 88;
    int result = great(a , b , c);
    cout<<"Greater Number is "<<result;
    return 0;
}