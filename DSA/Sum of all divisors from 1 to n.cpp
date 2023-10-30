# GFG Problem
# Link: https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
# Refer driver code from link above

# Main Code 
class Solution{
public:
    long long sumOfDivisors(int n){
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans += i*(n/i);
        }
        return ans;
    }
};
