
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:

        d = {}
        for x in nums:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1
                
        return self.find(d, len(nums))

    def find(self, d, i):

        if i == 1: return [[k for k in d]]
        l = []

        for k in d:
            t = d.copy()
            if t[k] == 1:
                del t[k]
            else:
                t[k] -= 1
            for t in self.find(t, i - 1):
                l.append(t + [k])

        return l
      
