public class BinarySearchRec {
    public static void main(String agrs[]) {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        System.out.println("at: " + binarySearch(6, arr, 0, (arr.length - 1)));
    }

    static int binarySearch(int num, int arr[], int low, int high) {

        if (low > high)
            return -1;
        else {
            int mid = (low + high) / 2;

            if (num == arr[mid]) {
                return mid;
            } else if (num > arr[mid]) {
                return binarySearch(num, arr, (mid + 1), high);
            } else {
                return binarySearch(num, arr, low, (mid - 1));
            }

        }

    }
}
