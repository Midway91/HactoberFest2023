#include<iostream>
using namespace std;
class Parent final{
   
};

class Child:Parent{
   
};
int main()
{
    
    return 0;
}


// 04_final_02.cpp:7:7: error: cannot derive from 'final' base 'Parent' in derived type 'Child'
//  class Child:Parent{
//        ^~~~~
