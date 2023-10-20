#include<iostream>
using namespace std;
int main()
{
    int n , i;
    cout<<"Enter The Number\n";
    cin>>n;
    for(i = 1 ; i < 11 ; i++){
        cout<<n << 'X' << i<< '=' << n*i <<endl;
    }
    return 0;
}