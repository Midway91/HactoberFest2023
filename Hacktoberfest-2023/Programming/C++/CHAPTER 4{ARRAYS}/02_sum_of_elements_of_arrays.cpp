#include<iostream>
using namespace std;
int main()
{   
    int sum = 0;
    int arr[7] = {4 , 5 , 3 , 7 , 6 , 1 , 2 };
    for(int i = 0 ; i< 7 ; i++){
        sum = sum + arr[i];
    }
    cout<<sum;
    return 0;
}