/*
 * Here is the program to find the largest sum of the contiguous subarray.
 * I have used the Kadane's algorithm to solve the problem.
 * The Time Complexity of the program using Kadane's algorithm is O(n)
 * contributed by swarupsahu08
 */

import java.util.Scanner;
import java.lang.Math;

public class contiguous_subarray {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array");
        int n=sc.nextInt();
        int []arr=new int[n];
        System.out.println("Enter the elements of the array");
        for (int i = 0; i < n; i++) {
            arr[i]=sc.nextInt();
        }
        System.out.println("These are the elements of the array entered by you:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]+" ");
        }
        int sum=0;
        int maxele=arr[0];
        for (int i = 0; i < n; i++) {
            sum+=arr[i];
            maxele=Math.max(maxele, sum);
            if (sum<0) {
                sum=0;
            }
        }
        System.out.print("\n");
        System.out.println("The maximum sum of the contiguous subarray is "+maxele);


    }
}
