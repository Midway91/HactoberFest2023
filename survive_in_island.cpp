// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sunday = S/7;
        int buyingdays = S-sunday;
        int totalfood = S*M;
        int ans = 0;
        if (totalfood % N == 0){
            ans = totalfood/N;
        }
        else{
            ans = (totalfood/N)+1;
        }
        if (ans<=buyingdays){
            return ans;
        }
        else{
            return -1;
        }
    }
};