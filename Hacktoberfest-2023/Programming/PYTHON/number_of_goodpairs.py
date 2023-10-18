class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        # Initialize a dictionary to store the frequency of each number.
        hashMap = {}
        
        # Initialize a variable to store the result.
        res = 0
        
        # Iterate through the given list of numbers.
        for number in nums:
            # Check if the number is already in the dictionary.
            if number in hashMap:
                # If it's in the dictionary, increment the result by the current count
                # and then update the count for the number in the dictionary.
                res += hashMap[number]
                hashMap[number] += 1
            else:
                # If the number is not in the dictionary, add it with a count of 1.
                hashMap[number] = 1
        
        # Return the final result, which represents the number of identical pairs.
        return res
