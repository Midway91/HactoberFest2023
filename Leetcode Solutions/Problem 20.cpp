class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]== '(' || s[i]== '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else{
                 if(st.empty())return false;
                 else if(s[i]==')' and st.top()!='(')return false;
                 else if(s[i]=='}' and st.top()!='{')return false;
                 else if(s[i]==']' and st.top()!='[')return false;
                 st.pop();
            }

        }
        
        if(st.empty())return true;
        return false;

    }
};
