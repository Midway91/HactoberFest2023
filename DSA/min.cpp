#include<iostream>
using namespace std;
int main(){

int arr[]={11,2,33,4,5};
int mini=INT_MAX16;
for(int i=0;i<5;i++){
if(arr[i]<mini){
mini=arr[i];
}
cout<<mini;
return 0;
}
