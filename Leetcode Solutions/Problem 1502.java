class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int i,j;
        for(i=arr.length-1;i>=0;i--){
            for(j=0;j<i;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        for(i=0;i<arr.length-2;i++){
            if((arr[i+1]-arr[i])!=(arr[i+2]-arr[i+1])){
                return false;
            }
        }
        return true;
    }
}
