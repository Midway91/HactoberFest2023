public class KadaneAlgo {
    public static int kadane(int[] arr){
        int currSum=arr[0];
        int overallSum=arr[0];

        for(int i=1 ;i< arr.length;i++){
            if(currSum >=0){
                currSum = currSum+arr[i];
            }else{
                currSum = arr[i];
            }
            if(currSum>overallSum){
                overallSum=currSum;
            }
        }
        return overallSum;
    }
    public static void main(String[] args) {
        int[] arr = {4,3,-2,6,-14,7,-1,4,5,7,-10,2,9,-10,-5,-9,6,1};
        System.out.println(kadane(arr));
    }
}

