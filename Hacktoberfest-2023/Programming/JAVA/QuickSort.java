public class QuickSort {
    // Function to perform the quick sort
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the index of the pivot element
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the subarrays on both sides of the pivot
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Function to partition the array
    public static int partition(int[] arr, int low, int high) {
        // Choose the rightmost element as the pivot
        int pivot = arr[high];

        // Initialize the index of the smaller element
        int i = low - 1;

        // Iterate through the array
        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                // Swap arr[i] and arr[j]
                i++;
                swap(arr, i, j);
            }
        }

        // Swap arr[i+1] and arr[high] (pivot)
        swap(arr, i + 1, high);

        // Return the index of the pivot element
        return i + 1;
    }

    // Function to swap two elements in an array
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 3, 6};
        int n = arr.length;

        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        quickSort(arr, 0, n - 1);

        System.out.println("\nSorted Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
