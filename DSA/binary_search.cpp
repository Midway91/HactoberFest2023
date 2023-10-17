class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int low = 0;
        int high = n-1;
        int mid = (high + low)/2;
        while(high >= low) {
            mid = (low + high)/2;
            if(arr[mid] == k) {
                return mid;
            }
            else if(k > arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        
        return -1;
    }
};
