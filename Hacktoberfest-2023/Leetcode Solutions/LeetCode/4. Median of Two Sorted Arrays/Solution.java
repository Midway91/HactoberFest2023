// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {

    int[] mergeArrays(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;

        int res[] = new int[n + m];

        int i = 0, j = 0, idx = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                res[idx++] = arr1[i++];
            } else {
                res[idx++] = arr2[j++];
            }
        }

        while (i < n) {
            res[idx++] = arr1[i++];
        }

        while (j < m) {
            res[idx++] = arr2[j++];
        }

        return res;
    }

    public double findMedianSortedArrays(int[] arr1, int[] arr2) {
        int res[] = mergeArrays(arr1, arr2);

        int len = res.length;
        int mid=res.length/2;
        double median=0.0;
        
        if (len % 2 == 1) {
            median = res[mid];
        }
        else{
            median = (res[mid]+res[mid-1])/2.0;
        }
        return median;
    }
}
