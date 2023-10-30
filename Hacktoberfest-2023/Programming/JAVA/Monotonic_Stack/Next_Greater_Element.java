class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int[] ans = new int[n1];

        

        for(int i=0; i<n1; i++){
            int j=0;

            while(nums1[i] != nums2[j]){
                j++;
            }

            ans[i] = findNGE(j, nums2);
        }

        return ans;
    }

    public int findNGE(int j, int[] nums2){
        Stack<Integer> st = new Stack<>();

        int ng = -1;
        int n = nums2.length;
        int k = n-1;
        while(k>=j){
            while(!st.isEmpty() && st.peek() < nums2[k]){
                st.pop();
            }
            if(st.isEmpty()){
                ng = -1;
            }else{
                ng = st.peek();
            }
            st.push(nums2[k]);
            k--;
        }

        return ng;
    }
}
