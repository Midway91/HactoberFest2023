#include<iostream>
using namespace std;
int main()
{
    [](){cout<<"Hello"<<endl;}();
    [](int x , int y){cout<<"sum is "<<x+y<<endl;}(10 , 30);
    cout<<([](int x , int y){return x+y;}(10,54))<<endl;
    int a = [](int x , int y){return x+y;}(87,54);
    cout<<a<<endl;
    int b = [](int x , int y)->int{return x+y;}(9,54);
    cout<<b<<endl;
    int x = 24;
    [x](){cout<<x<<endl;}();
    int y  = 43;
    auto f = [y](){cout<<y<<endl;};
    f();
    f();

    auto k = [&y](){cout<<++y<<endl;};
    k();
    return 0;
}