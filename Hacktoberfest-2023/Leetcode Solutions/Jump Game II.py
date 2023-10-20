
class Solution:
    def jump(self, fuel: List[int]) -> int:
        num_planes = 0
        current_fuel = 0
    
        for i in range(len(fuel)):
            current_fuel += fuel[i]
            if current_fuel < 0:
                num_planes += 1
                current_fuel = 0
                
        if current_fuel < 0:
            return -1

        return num_planes
      
