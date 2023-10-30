//import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window
        int right = 0; // Right pointer of the sliding window
        HashSet<Character> windowChars = new HashSet<>(); // Set to store characters in the current window

        while (right < n) {
            char currentChar = s.charAt(right);
            if (!windowChars.contains(currentChar)) {
                // If the character is not in the window, expand the window to the right
                windowChars.add(currentChar);
                maxLength = Math.max(maxLength, right - left + 1);
                right++;
            } else {
                // If the character is in the window, contract the window from the left
                windowChars.remove(s.charAt(left));
                left++;
            }
        }

        return maxLength;
    }
}
