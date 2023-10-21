class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;
        int maxLen=0;
        st.push(-1);
        
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='('){
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else
                {
                    int len=i-st.top();
                    maxLen=max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};