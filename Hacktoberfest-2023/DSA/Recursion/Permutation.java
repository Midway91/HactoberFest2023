import java.io.*;
import java.util.*;
class Ankit_Permutaion_Solution {
    private void recurPermute(int index, int[] nums, List < List < Integer >> ans) {
        if (index == nums.length) {
            // copy the ds to ans
            List < Integer > ds = new ArrayList < > ();
            for (int i = 0; i < nums.length; i++) {
                ds.add(nums[i]);
            }
            ans.add(new ArrayList < > (ds));
            return;
        }
        for (int i = index; i < nums.length; i++) {
            swap(i, index, nums);
            recurPermute(index + 1, nums, ans);
            swap(i, index, nums);
        }
    }
    private void swap(int i, int j, int[] nums) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    public List < List < Integer >> permute(int[] nums) {
        List < List < Integer >> ans = new ArrayList < > ();
        recurPermute(0, nums, ans);
        return ans;
    }
};

class PermutationsFind {
    public static void main(String[] args) {
        int nums[] = {1,2,3};
        Ankit_Permutaion_Solution sol = new Ankit_Permutaion_Solution();
        List < List < Integer >> ls = sol.permute(nums);
        System.out.println("All Permutations are");
        for (int i = 0; i < ls.size(); i++) {
            for (int j = 0; j < ls.get(i).size(); j++) {
                System.out.print(ls.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}