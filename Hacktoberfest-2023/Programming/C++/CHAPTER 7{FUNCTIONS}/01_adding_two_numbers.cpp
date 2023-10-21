#include <iostream>
using namespace std;
int sum(int x, int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int x = 10, y = 20;
    int z = sum(x, y);
    cout << "Sum Is " << z;
    return 0;
}