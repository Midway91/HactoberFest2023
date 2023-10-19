#include<iostream>
using namespace std;
int main()
{
    int arr[10], n;
    for(int i = 0 ; i < 10 ; i++){
        cin>>arr[i];
    }
    cout<<"Enter The Number";
    cin>>n;
    for( int j = 0 ; j< 10 ; j++){
        if(arr[j] == n ){
            cout<<"Found At"<<j;
            return 0;
        }
       
    }
    cout<<"Unsuccessful";

    return 0;
}