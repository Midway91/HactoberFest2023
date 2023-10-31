class Solution {
public:

    bool checkPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0, j = s.length()-1;

        while(i<j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                // s[i]!=s[j]
                // 1 removal allowed
                // after removal check palindrome
            
            // ith char removal
            bool ans1 = checkPalindrome(s,i+1,j);
            // jth char removal
            bool ans2 = checkPalindrome(s,i,j-1);

                 return ans1 || ans2;
            }
        }
        // valid palindrome -> 0removal
        return true;

    }
};
