#include<iostream>
using namespace std;
void Display(){
    cout<<"Hello"<<endl;
}
int main()
{
    void (*fp)();  
    fp = Display;
    (*fp)();
    return 0;
}