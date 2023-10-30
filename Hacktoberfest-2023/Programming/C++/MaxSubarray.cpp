class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+curr_sum >= nums[i])
                curr_sum+=nums[i];
            else
                curr_sum=nums[i];
            ans = max(ans , curr_sum);
        }
        return ans;
    }
};
