#include<iostream>
using namespace std;
class Base{
    public:
        void fun1(){
            cout<<"hi";
        }
        void fun2();
};
class Derived :public Base{
    public:
        void fun3();
        void fun4();
};
int main()
{
    Base *ptr;
    ptr = new Derived();
    ptr->fun1();
    // ptr->fun3();
    return 0;
}