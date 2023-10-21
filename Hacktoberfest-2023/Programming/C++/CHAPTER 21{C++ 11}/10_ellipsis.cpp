#include<iostream>
#include <cstdarg>
using namespace std;
int sum(int n , ...){
    va_list list;
    va_start(list , n);
    int x;
    int s = 0;
    for(int i = 0 ; i < n ; i++){
        x = va_arg(list , int);
        s+=x;
    }
    va_end(list);
    return s;

}
int main()
{
    cout<<sum(3,10,201,32)<<endl;
    cout<<sum(5,30,40,50,60,70)<<endl;
    return 0;
}