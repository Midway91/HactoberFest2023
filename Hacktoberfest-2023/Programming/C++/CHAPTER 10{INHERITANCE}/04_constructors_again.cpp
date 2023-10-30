#include<iostream>
using namespace std;
class Base{
    public:
        Base(){
            cout<<"Default In Base"<<endl;
        }
         Base(int x){
            cout<<"Param In Base "<<x<<endl;
        }
};
class Derived:public Base{
    public:
        Derived(){
            cout<<"Default In Derived"<<endl;
        }
        Derived(int y){
            cout<<"Param In Derived "<<y<<endl;
        }
        Derived(int x , int y):Base(x){
            cout<<"Param In Derived "<<y<<endl;
        }
};

int main()
{
    Derived d;   
    Derived e(10);
    Derived f(20 , 30);
    return 0;
}