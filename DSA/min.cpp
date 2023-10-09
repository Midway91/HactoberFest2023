#include<iostream>
using namespace std;
int main(){

int arr[]={11,2,33,4,5};
int min=INT_MAX16;
for(int i=0;i<5;i++){
if(arr[i]<min){
min=arr[i];
}
cout<<min;
return 0;
}
