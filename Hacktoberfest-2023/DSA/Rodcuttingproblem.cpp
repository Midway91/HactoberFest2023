#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, prices[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    int max_profit = maxProfit(prices, n);
    cout << "Maximum profit: " << max_profit << endl;

    return 0;
}
