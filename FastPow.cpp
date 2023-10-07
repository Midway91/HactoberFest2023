#include<iostream>
using namespace std;
int FastPow(int n,int k){
    int ans=1;
    while(k>0){
        if(k&1){
            ans=ans*n;
        }
        n=n*n;
        k=k>>1;
    }
    return ans;
}
int main(){
  cout<<FastPow(10,9)<<endl;
}