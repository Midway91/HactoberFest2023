#include<iostream>
using namespace std;
int main(){

int arr[]={11,2,33,4,5};
int max=INT_MIN16;
for(int i=0;i<5;i++){
if(arr[i]>max){
max=arr[i];
}
cout<<max;
return 0;
}
