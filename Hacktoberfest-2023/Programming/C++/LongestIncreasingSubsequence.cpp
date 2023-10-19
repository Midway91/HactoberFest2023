#include<bits/stdc++.h>
using namespace std;
#define int long long

int inf = 1e9+7;


void solve(){
    int n ;
    cin>>n;
    vector<int>v(n,0);
    // Take input array
    for(auto &i: v)cin>>i;

    vector<int>dp(n+1,inf);
    dp[0]=0;
    
  
    for(int i=0;i<n;i++){

            int a = v[i];
            //   binary search for a index at which value is less than a
            int l=0;
            int r=n;
            while(r-l>1){
                int mid =(l+r)/2;
                if(dp[mid]>a){
                    r = mid;
                }
                else{
                    l=mid;
                }
               
            }
            // each index represent length of logest increasing subsequence
            // and element at particular index represent last element of particular length LIS that would be minimum as possible
          
            if(dp[r]<a and r<n)dp[r+1]=min(dp[r+1],a);
            if(dp[l]<a )dp[r]=min(dp[r],a);
           
     }

     int ans =0;
    
     for(int i=0;i<=n;i++){
        if(dp[i]==inf)break;
        ans=i;
     }
   
cout<<ans<<endl;

return;


}

signed main(){
    solve();
}