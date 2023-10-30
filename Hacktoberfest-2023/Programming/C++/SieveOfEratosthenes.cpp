//Sieve of Eratosthenes  o(n log log n)
#include<iostream>
#include<vector>
using namespace std;
vector<int>prime;
void seive(vector<bool>&arr,int n){
    for(int i=2;i*i<=n;i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=false;
            }
        }
    }
    arr[2]=true;
    arr[0]=arr[1]=false;
    for(int i=2;i<n;i++){
        if(arr[i]){
        prime.push_back(i);
        }
    }
}
int main(){
   
    int n;
    cin>>n;
    vector<bool>arr(n+1,true);
    
    seive(arr,n);
    for(auto it :prime){
        cout<<it<<" ";
    }
}
