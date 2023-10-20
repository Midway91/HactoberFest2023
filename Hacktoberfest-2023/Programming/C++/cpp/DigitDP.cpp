/// calculate number of zero in range m to n(m<=n)

#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int MAX = 18;
int in() {int x; scanf("%d",&x); return x;}
ll lin() {ll x; scanf("%lld",&x); return x;}

int id, sz;
vector<int>num;
ll dp[MAX][MAX][2][2];
int visit[MAX][MAX][2][2];
ll go(int pos, int cnt, int isSmall, int isStart){
    /// cnt means how many zero in this number(3201 = 1 zero)
    if(pos==sz) return cnt;
    ll &ret = dp[pos][cnt][isSmall][isStart];
    int &vis = visit[pos][cnt][isSmall][isStart];
    if(vis==id) return ret;
    vis = id;
    ret = 0;
    int last = isSmall ? 9 : num[pos];
    if(isStart){
        for(int i=1; i<=last; i++){
            ret += go(pos+1, cnt, isSmall | i<num[pos], 0);
        }
        ret += go(pos+1, 0, 1, 1);  /// without this position
    }
    else{
        for(int i=0; i<=last; i++){
            ret += go(pos+1, (i==0)+cnt, isSmall | i<num[pos], 0);
        }
    }
    return ret;
}
ll solve(ll x){
    if(x<0) return 0;
    if(x<10) return 1;
    num.clear();
    while(x>0){
        num.pb(x%10);
        x/=10;
    }
    reverse(all(num));
    sz = num.size();
    id++;
    return 1+go(0, 0, 0, 1); /// 1 for zero
}
int main(){
    int t = in();
    for(int tc=1; tc<=t; tc++){
        ll m = lin();
        ll n = lin();
        ll ans = solve(n);
        ans -= solve(m-1);
        printf("Case %d: %lld\n", tc, ans);
    }
    return 0;
}
