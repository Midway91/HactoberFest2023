#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=5;
    int arr[] = {5,3,1,4,2};
    for(int ele:arr){
      cout<<ele<<" ";
    }
    cout<<endl;

    // insertion sort
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
      for(int ele:arr){
         cout<<ele<<" ";
       }
    return 0;

}
