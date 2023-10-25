#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref, suff(n);
        pref.push_back(nums[0]);
        suff[n-1] = nums[n-1];
        
        for(int i = 1 ;i < n ;i++) pref.push_back(min(nums[i], pref.back()));
        for(int i = n-2; i>=0 ; i--){
            suff[i] = min(nums[i], suff[i+1]);
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > pref[i] && nums[i] > suff[i]){
                ans = min(ans, pref[i] + suff[i] + nums[i]);
            }
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }

void solve(){
    int n ;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    cout << minimumSum(v) << endl;

}
int main(){
    #ifdef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1LL;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}