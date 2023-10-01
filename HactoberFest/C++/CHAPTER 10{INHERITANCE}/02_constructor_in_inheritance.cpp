#include<iostream>
using namespace std;
class base{
    public:
    base(){
        cout<<"Non Parameterised base constructor"<<endl;
    }
    base(int x){
        cout<<"Parameterised base constructor "<<x<<endl;
    }
};
class derived:public base{
    public:
    derived(){
        cout<<"Non Parameterised derived constructor"<<endl;
    }
    derived(int a){
        cout<<"parameterised derived constructor "<<a<<endl;
    }
    derived(int x , int a):base(a){
        cout<<"parameterised derived constructor "<<a<<endl;
    }
};

int main()
{
    derived d;
    derived f(30);
    derived j(10 , 30);
    
    return 0;
}           