class Solution {
    public String getPermutation(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        
        int count = 1;
        while (count < k) {
            nextGreaterPermutation(nums);
            count++;
        }
        
        StringBuilder result = new StringBuilder();
        for (int num : nums) result.append(num);
        
        return result.toString();
    }
    
    private void nextGreaterPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 1;
        // Find the fist digit(pivot) from the last which is smaller than the next
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        
        // if i = 0, means all the digits are in descending order, no next greater permutation
        if (i > 0) {
            // Find the digit just greater than the pivot digit
            int x = nums[i - 1];
            int minIndex = n - 1;
            while (nums[minIndex] <= x) {
                minIndex--;
            }
            
            // Swap the pivot digit with the next greater digit
            swap(nums, i - 1, minIndex);
            // Need to reverse the remaing digits for next greater permutation
            reverse(nums, i, n - 1);
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i++, j--);
        }
    }
}
