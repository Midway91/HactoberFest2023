#include<iostream>           
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout << "enter the size of array : ";
    cin >> n;
    int arr[1000];
    for(int i=0;i<=n-1;i++){
        cout << "enter elements of array : ";
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int target;
    cout << "enter target value : ";
    cin >> target;
    int i=0;
    int j=n-1;
    while(i<j){
        int pairsum=arr[i]+arr[j];
        if(pairsum==target){
            cout << arr[i] << " and "<< arr[j]<< endl;
            i++;
            j--;
        } else if(pairsum>target){
            j--;
        }else{
            i++;
        }
    }
    return 0;
}
