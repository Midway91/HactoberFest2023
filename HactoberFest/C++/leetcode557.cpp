// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Example 2:
// Input: s = "God Ding"
// Output: "doG gniD"
 

// Constraints:
// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

class Solution {
public:
    string reverseWords(string s) {
        s += ' ';
        int firstEle = 0, lastEle, sLen = s.size();
        for(int i = 0; i < sLen; i++){
            if(s[i] == ' ' || i+1 == sLen){
                lastEle = i-1;
                for(int j = firstEle, k = lastEle; j < k; j++, k--){
                    char temp = s[j];
                    s[j] = s[k];
                    s[k] = temp;
                }
                firstEle = i+1;
            }
        }
        s.pop_back();
        return s;
    }
};
