#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> t;

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = arr[tl];
    }else{
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

int get_query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }if(tl == l and tr == r){
        return t[v];
    }
    int tm = (tl + tr)/2;
    return gcd(get_query(v*2, tl, tm, l, min(r, tm)), get_query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int nval){
    if(tl == tr){
        t[v] = nval;
    }else{
        int tm = (tl + tr) / 2;
        if(tm >= pos){
            update(v*2, tl, tm, pos, nval);
        }else{
            update(v*2+1, tm+1, tr, pos, nval);
        }
        t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    #include "C://Users//hhars//OneDrive//Documents//CPP Practice//Algo/config.h"   // include definitions
#endif

cin>>n;

arr = vector<int>(n);
t = vector<int>(4*n);

for(auto &x: arr){ cin>>x; }

int pos, nval, l, r, q, x;
build(1, 0, n-1);
cin>>q;
while(q > 0){
    cin>>x;
    if(x == 1){
        cin>>pos>>nval;
        update(1, 0, n-1, pos, nval);
        arr[pos] = nval;
    }else{
        cin>>l>>r;
        int ans = get_query(1, 0, n-1, l, r);
        cout<<"=> "<<ans<<endl;
    }
    q--;
}

return 0;
}
