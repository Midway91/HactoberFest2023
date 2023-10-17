// bst que advanced
#include<iostream>
using namespace std;
class Solution {
public:
   long long int binary(int n){
         int s=0;
        int e=n;
        long long int m=s+(e-s)/2;
       
       long long int ans=-1;
        while(s<=e){
            long long  int square=m*m;
            if(square==n)
                return m;
            
            if(square<n){
                ans=m;
                s=m+1;
            }
            else{
               e=m-1; 
            }
             m=s+(e-s)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
       
         return binary(x);
    }
};
//  q1 find pivot in array
// int getPivoT(int arr[],int n){
//     int s=0;
//     int e=n-1;
//     int m=(s+e)/2;
//     while (s<e)
//     {
//    if (arr[m]>=arr[0])
//    {
//    s=m+1;
//    }
//    else{
//     e=m;
//    }
//     m=(s+e)/2;
//     }
//     return s;
// }
// int bst(int arr[],int s,int e,int key){
//     int start=s;
//     int end=e;
//     int mid=(start/2) +(end/2);
//     while(start<end){

// if(key==arr[mid]){
//     return mid;
// }
// else if(key>arr[mid]){
//     start=mid+1;
  
// }
// else if(key<arr[mid]){
//     end=mid-1;
// }
// mid=(start/2) +(end/2);
// }
// return -1;
// }
// int findpos(int arr[],int n,int k){
//     int pivot=getPivoT(arr,n);
//     if(k>=arr[pivot] && k<=arr[n-1]){
//         return bst(arr,pivot,n-1,k);

//     }
//     else{
//         return bst(arr,0,pivot-1,k);
//     }
// }
// square root using binary search

int main(){
  int x=mySqrt(50);
}