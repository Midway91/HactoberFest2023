#include<iostream>
using namespace std;
int main()
{
    int x = 20;
    const int *ptr = &x;
    // ++*ptr; not possible
    return 0;
}