#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int missingNumber(vector<int>& a, int n) {
        // Your code goes 
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(i<n)
            s=s^(i^a[i-1]);
            else
            s=s^i;
        }
        return s;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
