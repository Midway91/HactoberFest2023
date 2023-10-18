#include<iostream>
using namespace std;
int main()
{
    int arr[7] = {5 , 6 , 9 , 8 , 3 , 1 , 2};
    int grt = arr[0];
    for(int i = 1 ; i < 7 ; i++){
        if(arr[i]>grt){
            grt = arr[i];
           
        }
       
    }
    cout<<grt;
    return 0;
}