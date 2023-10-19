import java.util.*;
public class OrderAgnosticBS{

    static int orderagBS(int[] a , int target){
        int start=0;
        int end=a.length-1;
        //main condition
        boolean isAsc=a[start]<a[end];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==a[mid]){
                return mid;
            }

            if(isAsc){
                if(a[mid]>target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            if(!isAsc){
                if(a[mid]>target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
    public static void main(String[] args){
        //order agnostics Binary search is used when we're given a SORTED ARRAY but don't know
        //if it is in INCREASING ORDER OR DECREASING ORDER
        //ALGORITHM
        /*
          start > end ===>>DESCENDING ORDER SORTED ARRAY
          start < end ===>>ASCENDING ORDER SORTED ARRAY
          Simply apply binary search alh=gorithm 
         */

         //example
         int[] arr={10,9,8,7,6,5,4,3,2,1,0};
         int target=99;
         int ans=orderagBS(arr, target);
         System.out.println(ans);
    }
}