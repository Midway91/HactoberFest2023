class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int max=0;
        for(int i=0;i<nums1.length;i++)
        {
            if(max>(nums1.length-i))
            {return max;}
            for(int j=0;j< nums2.length;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    int x=i+1;
                    int y=j+1;
                    int count=1;
                    while((x< nums1.length && y<nums2.length ) && (nums1[x]==nums2[y]))
                    {
                        count++;
                        x++;
                        y++;
                    }
                    if(max<count)
                        max=count;
                }
            }
        }
    return max;
    }
}