#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

ll power(int base, ll exp)
{
    ll ans = 1;

    for (ll i = 0; i < exp; i++)
    {
        ans *= base;
    }
    return ans;
}
void TOH(int a, int b, int c, int n)
{

    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }
    TOH(a, c, b, n - 1); // src to auxiliary
    cout << a << " " << c << endl;
    TOH(b, a, c, n - 1); // auxiliary to destination
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << power(2, n) - 1 << endl;
    TOH(1, 2, 3, n);
    return 0;
}
