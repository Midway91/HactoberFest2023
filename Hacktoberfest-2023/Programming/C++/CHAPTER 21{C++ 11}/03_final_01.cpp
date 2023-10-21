#include<iostream>
using namespace std;
class Parent{
    virtual void fun() final{

    }
};

class Child:Parent{
    void fun(){

    }
};
int main()
{
    
    return 0;
}

// 03_final_01.cpp:10:10: error: virtual function 'virtual void Child::fun()'
//      void fun(){
//           ^~~
// 03_final_01.cpp:4:18: error: overriding final function 'virtual void Parent::fun()'
//      virtual void fun() final{
//                   ^~~