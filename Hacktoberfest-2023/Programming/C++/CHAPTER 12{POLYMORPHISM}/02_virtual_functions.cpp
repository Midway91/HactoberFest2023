#include<iostream>
using namespace std;
class Base{
    public:
        virtual void fun(){
            cout<<"fun  of Base";
        }
};
class Derived :public Base{
    public:
        void fun(){
            cout<<"fun of Derived";
        }
        void fun2(){
            cout<<"hello";
        }
};

int main()
{
    Base *ptr = new Derived();
    ptr ->fun();
    // ptr ->fun2();
    return 0;
}