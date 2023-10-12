
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        hashmap = {}
        ans = []
        
        for num in nums:
            if num not in hashmap.keys():
                hashmap[num] = 1
                
            else:
                hashmap[num] += 1
        
        for ind,val in hashmap.items():
            if val > n/3:
                ans.append(ind)
        
        return ans

