class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;
        int res[]=new int[n-k+1];
        Deque<Integer> q=new ArrayDeque<>();
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(!q.isEmpty() && q.peek()==i-k) q.poll();
            while(!q.isEmpty() && nums[q.peekLast()]<=nums[i]) q.pollLast();
            q.offer(i);
            if(i>=k-1) res[r++]=nums[q.peek()];
        }
        return res;
    }
}
