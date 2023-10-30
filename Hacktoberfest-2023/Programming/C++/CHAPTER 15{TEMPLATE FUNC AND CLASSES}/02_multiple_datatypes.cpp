#include<iostream>
using namespace std;
template <class T , class R>
void add(T x , R y){
    cout<<x + y;
}
int main()
{
    add(2 , 2.1);
    return 0;
}