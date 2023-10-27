class Solution:
    def twoSum(self,nums: list, target: int):
        dist={}
        
        for i,val in enumerate(nums):
            
            key=target-val
            
            if key in dist:
                return [dist[key],i]
            else:
                dist[val]=i
