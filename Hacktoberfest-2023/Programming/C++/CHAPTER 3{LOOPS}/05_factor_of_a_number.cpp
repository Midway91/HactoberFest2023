#include<iostream>
using namespace std;
int main()
{
    int n , i ;
    cout<<"Enter The Number\n";
    cin>>n;
    cout<<"Prime Factors Are\n";
    for(i=1 ; i<=n ;i++){
        if(n%i == 0){
            cout<<i<<endl;
        }
    }
    return 0;
}