class Solution {
public:
    int reverse(int n) {
        int digit;
        long long int ans=0;
        if(n== -2147483648){
           return 0; 
        }
        if(n>0){
            while(n>0){
            digit= n%10;
            n= n/10;
            ans= ans*10+ digit;
            }
            if(ans> INT_MAX){
                return 0;
            }
            return ans;
        }
        else{
            n= n*(-1);
            while(n>0){
                digit= n%10;
                n= n/10;
                ans= ans*10+ digit;
            }
            if(ans> INT_MAX){
                return 0;
            }
            return ans*(-1);
        }
        return 0;
    }
};
