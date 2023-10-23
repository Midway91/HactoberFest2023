2909. Minimum Sum of Mountain Triplets II
You are given a 0-indexed array nums of integers.

A triplet of indices (i, j, k) is a mountain if:

i < j < k
nums[i] < nums[j] and nums[k] < nums[j]
Return the minimum possible sum of a mountain triplet of nums. If no such triplet exists, return -1.

Constraints:

3 <= nums.length <= 10^5
1 <= nums[i] <= 10^8