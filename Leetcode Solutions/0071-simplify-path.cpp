class Solution {
public:
    string simplifyPath(string path) {
        
        // tokenizing krna it means  input to string me break krna 
        
        string token="";
        stringstream abhishek(path);  // stringsteam is keyword and abhishek is variable 
        
        
    //Ans store krne k liye string
        stack<string>st;
        
        
        while(getline (abhishek,token,'/'))  //  getline keyword is use for abhishek variable and token string  and divided by /
        {
            if(token=="" || token=="." ) continue;
            
            if(token != "..")
            {
                st.push(token);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }
        
        if(st.empty()) return "/";
        
        string result="";
        
        while(!st.empty())
        {
            result= "/"+ st.top() +result;
            st.pop();
        }
        return result;
    }
};