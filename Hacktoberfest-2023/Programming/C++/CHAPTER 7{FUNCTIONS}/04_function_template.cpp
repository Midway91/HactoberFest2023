#include<iostream>
using namespace std;

template <class t>
t maxi(t a , t b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    int c = maxi(10 , 3);
    float d = maxi(1.2 , 5.5);
    cout<<c<<endl;
    cout<<d<<endl;
    return 0;
}