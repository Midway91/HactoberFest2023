#include<iostream>
using namespace std;
int main()
{
    int a = 10 , b = 0 , c ;
    try{
        if(b == 0){
            throw 101;
        }
        c = a/b;
        cout<<a;
    } catch(int e){
        cout<<"Divivsion By 0. Error "<<e;
    }
    return 0;
}