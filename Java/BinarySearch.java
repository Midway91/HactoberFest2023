import java.util.Scanner;

public class BinarySearch {

    // Binary search function
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the target is at the middle
            if (arr[mid] == target) {
                return mid;
            }

            // If the target is greater, ignore the left half
            if (arr[mid] < target) {
                left = mid + 1;
            }
            // If the target is smaller, ignore the right half
            else {
                right = mid - 1;
            }
        }

        // Target not found in the array
        return -1;
    }

public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the array using scanner class
        System.out.print("Enter the sorted array (comma-separated values): "); //input type comma-separated values
        String input = scanner.nextLine();
        String[] elements = input.split(",");
        int[] arr = new int[elements.length];

        for (int i = 0; i < elements.length; i++) {
            arr[i] = Integer.parseInt(elements[i].trim());
        }

        // Prompt the user to enter the target element using scanner class
        System.out.print("Enter the target element: ");
        int target = scanner.nextInt();

        int result = binarySearch(arr, target);

        if (result != -1) {
            System.out.println("Target found at index " + result);
        } else {
            System.out.println("Target not found in the array.");
        }

        scanner.close();
    }
}
