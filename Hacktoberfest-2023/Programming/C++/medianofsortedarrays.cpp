#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        
        
      

        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
       
        int nums1_size = nums1.size();
        sort(nums1.begin(),nums1.end());

        if (nums1_size%2 !=0)
        {
            int mid = (nums1_size)/2;
            return (float) nums1[mid];

        }

        else
        {
            int m1 = (nums1_size)/2;
            int m2 = m1+1;
            float k1 = nums1[m1-1];
            float k2 = nums1[m2-1];
            float k = (k1+k2)/2;
            return k;

        }

        
    };
};

int main(){
    Solution solution;
    vector <int> v1 = {2,3,5,6};
    vector <int> v2 = {8,3,5,6}; 
    int result = solution.findMedianSortedArrays(v1,v2);
    cout<<result;
}