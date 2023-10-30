import java.util.*;
public class FloorAndCeil {
    //for ceil of number return -----> a[low]
    public static int ceilNumber(int[] a , int size , int target){
        int low=0;
        int high=size-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]==target){
                return a[mid];
            }

            else if(a[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return a[low];
    }

    //for floor of number return -----> a[high]

    public static int floorNumber(int[] a , int size , int target){
        int low=0;
        int high=size-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]==target){
                return a[mid];
            }

            else if(a[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return a[high];
    }


    public static void main(String[] args){
        Scanner s= new Scanner(System.in);
        int[] arr={2,3,5,7,9,14,15,16,18};
        System.out.println("Enter the target : ");
        int target=s.nextInt();
        int n=arr.length;
        int ceilOfnumber = ceilNumber(arr,n,target);
        int floorOfnumber = floorNumber(arr,n,target);
        System.out.println("Ceiling of "+target+" = "+ceilOfnumber);
        System.out.println("Floor of "+target+" = "+floorOfnumber);
    }
}
