class Solution {
public:
    string decodeMessage(string key, string message) {
        //create mapping
        char start = 'a';
        char mapping[1000] = {0};

        for(auto ch: key) {
            if(ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }   
        //use mapping
        string ans;

        for(auto ch: message) {
            if(ch == ' ') {
                ans.push_back(' ');
            }
            else {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
    return ans;
    }
};