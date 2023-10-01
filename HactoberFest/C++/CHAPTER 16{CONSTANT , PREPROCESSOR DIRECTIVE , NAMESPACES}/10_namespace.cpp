#include<iostream>
using namespace std;
namespace First{
    void fun(){
        cout<<"First"<<endl;
    }
};
namespace Second{
    void fun(){
        cout<<"Second"<<endl;
    }
};
int main()
{
    First::fun();
    Second::fun();
    return 0;
}