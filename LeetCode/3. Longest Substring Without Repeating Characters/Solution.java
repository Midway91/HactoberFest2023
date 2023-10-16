// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), longest = 0;
        int[] nextIndex = new int[128]; 

        for (int r=0, l=0; r<n; r++) {
            l = Math.max(nextIndex[s.charAt(r)], l); 
            longest = Math.max(longest, r - l + 1);
            nextIndex[s.charAt(r)] = r + 1;
        }

        return longest;
    }
}
