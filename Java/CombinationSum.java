import java.util.ArrayList;

public class CombinationSum {
    public static void combination(int arr[],ArrayList <Integer> listt, int start,int sum,int k){
        if(sum==k){
            System.out.println(listt.toString());
            return;
        }
        if(sum>k){
            return;
        }
        if(start==arr.length){
            return;
        }
        listt.add(arr[start]);
        sum=sum+arr[start];
        combination(arr,listt,start+1,sum,k);
        listt.remove(listt.size()-1);
        sum-=arr[start];
        combination(arr, listt, start+1,sum,k);


    }
    public static void main(String[] args) {
        int arr[]={1,1,1,2,2};
        combination(arr, new ArrayList <Integer> (), 0, 0, 3);
        

    }
}
