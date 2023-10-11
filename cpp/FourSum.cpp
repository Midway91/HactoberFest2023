#include<bits/stdc++.h>
using namespace std;
bool fourSum(vector<long long int> arr, long long int target, long long int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int left=target-(arr[i]+arr[j]);
        int strt=j+1;
        int end=n-1;
        while(strt<end){
          int k=arr[strt]+arr[end];
          
          if(k==left)return "Yes";
          else if(k<left){
            strt++;
          }
          else end--;
        }
      }
    }

    return "No";
}
int main(){
long long int n;
cin>>n;
vector<long long int> v;
for (int i = 0; i < n; i++)
{
   long long int x;
   cin>>x;
   v.push_back(x);
}
long long int target;
cin>>target;
cout<<fourSum(v,target,n)<<"\n";
}