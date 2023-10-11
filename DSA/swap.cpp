#include <iostream>
using namespace std;
//Program to swap two values using pointer
void swapp(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    int a=5;
    int b=2;
    cout<<a<<" "<<b<<endl;
    swapp(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}