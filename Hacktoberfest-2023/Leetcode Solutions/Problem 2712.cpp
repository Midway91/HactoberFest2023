#define ll long long
class Solution {
public:
    long long minimumCost(string s) {
    int length = s.size();  
    vector<ll> prefixSums(length, 0);  
    vector<ll> suffixSums(length, 0);  
    ll ans =LONG_LONG_MAX;
    for (int i = 1; i < length; i += 1) {
        prefixSums[i] = prefixSums[i - 1] + (s[i - 1] != s[i] ? i : 0);
    }
    for (int i = length - 2; i >= 0; i -= 1) {
        suffixSums[i] = suffixSums[i + 1] + (s[i] != s[i + 1] ? (length - i - 1) : 0);
    }

    ll res = suffixSums[0];  

    // Iterate through the string to calculate the minimum cost
    for (int i = 0; i < length; i += 1) {
        ans =min(ans, prefixSums[i] + res);
        if (i + 1 < length) {
            res -= (length - i - 1) * (s[i] != s[i + 1]);
        }
    }

    return ans;
    }
};