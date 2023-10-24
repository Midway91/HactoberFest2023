import java.util.Arrays;

public class quickSort{

  public static void main(String[] args) {

  int[] arr = {3,4,2,1};
  quick(arr, 0, arr.length-1);
  System.out.println(Arrays.toString(arr));
  
}
static void quick(int[] arr, int low, int high){
  if(low >= high){
    return;
  }
  int start = low;
  int end = high;
  int mid = low + (high - low) / 2;
  int pivot = arr[mid];

  while(start <= end){
  while(arr[start] < pivot){
    start++;
  }
  while(arr[end] > pivot){
    end--;
  }
  if(start <= end){
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    start++;
    end--;
  }
  }

  quick(arr,low,end);
  quick(arr,start,high);
}
}
