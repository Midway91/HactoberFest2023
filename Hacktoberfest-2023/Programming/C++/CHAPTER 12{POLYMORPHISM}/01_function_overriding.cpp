#include<iostream>
using namespace std;
class Base{
    public:
        void display(){
            cout<<"Display Of Base"<<endl;
        }
};
class Derived :public Base{
    public:
        void display(){
            cout<<"Display Of Derived";
        }
};

int main()
{
    Derived d;
    d.display();
    return 0;
}