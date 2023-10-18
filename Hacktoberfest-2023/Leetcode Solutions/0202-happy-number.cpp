class Solution {
public:
    bool isHappy(int n) {
        int ans =n;
        int digit;
        long square;
        int sum=0;
       while(true){
            while(n){
            digit = n %10;
            sum  = sum +pow(digit,2);
           n=n/10;
           
        }
            if(sum==1 || sum/10==0 && sum!=7){
           break;
       }
           
            n=sum;
           sum=0;
        }
        
        if(sum==1){
            return true;
        }
        else{
            return false;
        }
    }
};