#include<iostream>
using namespace std;
int main()
{
    int x = 30;
    int *const ptr = &x;
    int y = 10;
    // ptr = &y; not possible
    return 0;
}