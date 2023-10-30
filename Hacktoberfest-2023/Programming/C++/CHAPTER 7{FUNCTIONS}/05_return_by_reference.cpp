#include <iostream>
using namespace std;
int &fun(int &a)
{
    cout << a << endl;
    return a;
}
int main()
{
    int x = 25;
    fun(x) = 50;
    cout << x;
    return 0;
}