#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1 , 5 , 8 , 10 , 11 , 16 , 19 , 22 , 25 , 28 };
    int l = 0 , h = 9 , key , mid;
    cout<<"Enter The Key\n";
    cin>>key;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr[mid]){
            cout<<"Found At "<<mid;
            return 0;
        }
        else if(key < arr[mid]){
            h = mid -1;

        }
        else{
            l = mid + 1;
        }
    }
    cout<<"Not Found";
    return 0;
}