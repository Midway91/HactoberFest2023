class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int mini = 0;
        int buy = 0;
        int free = N-1;
        while (buy<=free){
            mini += candies[buy];
            buy++;
            free = free-K;
        }
        int maxi = 0;
        buy = N-1;
        free = 0;
        while (buy>=free){
            maxi += candies[buy];
            buy--;
            free = free+K;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};