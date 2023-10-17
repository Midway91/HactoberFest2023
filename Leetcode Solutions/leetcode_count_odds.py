"""
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
 

Constraints:

0 <= low <= high <= 10^9
"""
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        #* Using a loop won't work as it exceeds time constraints
        # oddCount = 0 
        # for i in range(low,high+1):
        #     if i%2 != 0:
        #         oddCount +=1 
        # return oddCount
        #* Here without using loop it can be solved in constant time complexity
        oddCount = 0
        if low%2 != 0:
            oddCount += 1
        if high%2 != 0:
            oddCount += 1
        difference = high-low-oddCount
        oddCount += int(difference/2)
        return oddCount

if __name__=="__main__":
    s1 = Solution() 
    print(s1.countOdds(3,9))