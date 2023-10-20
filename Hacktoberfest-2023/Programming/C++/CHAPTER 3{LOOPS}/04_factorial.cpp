#include<iostream>
using namespace std;
int main()
{
    int n , i , factorial =1;
    cout<<"Enter The Number\n";
    cin>>n;
    for(i=2 ; i<=n; i++){
        factorial = factorial*i;
    }
    cout<<factorial;
    return 0;
}