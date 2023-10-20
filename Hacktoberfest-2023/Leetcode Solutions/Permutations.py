
def Repermute(nums,ans,ds,feq):
    if(len(ds) == len(nums)):
        ans.append(ds.copy())
        return
    i = 0
    
    while(i<len(nums)):
        if(feq[i]==0):
            ds.append(nums[i])
            feq[i]  = 1
            Repermute(nums,ans,ds,feq)
            feq[i] = 0
            ds.pop()
        i += 1
    
class Solution:
       
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        ds = []
        feq = [0] * len(nums)
        
        Repermute(nums,ans,ds,feq)
        return ans
      
