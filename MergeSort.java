/**
 * The MergeSort class implements the merge sort algorithm for sorting an array
 * of integers.
 */
public class MergeSort {

    /**
     * This method performs the merge sort algorithm on the input array.
     *
     * @param arr The array to be sorted.
     */
    public static void mergeSort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return; // If the array is null or has only one element, it is already sorted.
        }
        int[] temp = new int[arr.length];
        mergeSort(arr, temp, 0, arr.length - 1);
    }

    /**
     * This method recursively divides the array and merges the divided parts.
     *
     * @param arr   The array to be sorted.
     * @param temp  The temporary array used for merging.
     * @param left  The leftmost index of the subarray.
     * @param right The rightmost index of the subarray.
     */
    private static void mergeSort(int[] arr, int[] temp, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, temp, left, mid);
            mergeSort(arr, temp, mid + 1, right);
            merge(arr, temp, left, mid, right);
        }
    }

    /**
     * This method merges two subarrays into a single sorted subarray.
     *
     * @param arr   The array to be sorted.
     * @param temp  The temporary array used for merging.
     * @param left  The leftmost index of the subarray.
     * @param mid   The middle index of the subarray.
     * @param right The rightmost index of the subarray.
     */
    private static void merge(int[] arr, int[] temp, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            temp[i] = arr[i];
        }
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                arr[k] = temp[i];
                i++;
            } else {
                arr[k] = temp[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            arr[k] = temp[i];
            k++;
            i++;
        }
    }

    // Main method to test the MergeSort implementation
    public static void main(String[] args) {
        int[] arr = { 12, 11, 13, 5, 6, 7 };
        mergeSort(arr);
        System.out.println("Sorted array: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
