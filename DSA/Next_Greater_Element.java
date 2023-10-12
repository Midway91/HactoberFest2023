/**
 * Question link :- https://leetcode.com/problems/next-greater-element-iii/
 */



class Solution {
    public int nextGreaterElement(int n) {
        String str = String.valueOf(n);
        char[] arr = str.toCharArray();
        int i = arr.length - 2;
        while(i>=0 && arr[i]>= arr[i+1]){
            i--;
        }
        if(i== -1){
            return -1;
        }
        int k = arr.length -1;
        while(arr[i] >= arr[k]){
            k--;
        }
        char temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        StringBuilder sb = new StringBuilder();
        for(int j=0;j<=i;j++){
            sb.append(arr[j]);
        }
        for(int j= arr.length-1; j>i; j--){
            sb.append(arr[j]);
        }
         try{
            return Integer.parseInt(sb.toString());
        }
        catch(Exception e){
            return -1;
        }
    }
}