#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9 + 7;

ll binExpIter(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

ll binExpRec(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll res = binExpRec(a, b / 2);
    if (b & 1)
    {
        return (res * res * a) % m;
    }
    return (res * res) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    cout<<binExpRec(4,20)<<endl;
    cout<<binExpRec(7,15)<<endl;

    return 0;
}
