public class InsertionSorting {
    public static void main(String[] args) {
        int arr[] = {3,2,6,1,9,4,10};
        for (int i = 1; i < arr.length; i++) {
            int j = i-1;
            int currentValue = arr[i];
            while(j>=0 && arr[j]>currentValue){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = currentValue;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
