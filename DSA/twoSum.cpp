#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numIndices;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numIndices.find(complement) != numIndices.end()) {
            return {numIndices[complement], i};
        }
        numIndices[nums[i]] = i;
    }
    return {}; // No solution found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    for (int index : result) {
        std::cout << index << " ";
    }
    return 0;
}
