package sort;

import java.util.Arrays;

/**
 * Quick Sort
 * <p>
 * Implementation Logic:
 * 1. Find the middle value based on the length of the array.
 * 2. Sort and swap the values on the left and right sides based on the middle value.
 * 2.1 Move elements smaller than the middle value from the right to the left of the middle value.
 * 2.2 Move elements larger than the middle value from the left to the right of the middle value.
 * 3. Recursively sort the elements on the left and right sides of the middle value again.
 * <p>
 * Deduction Process:
 * Initial array -> array = [-9,78,0,23,-567,70]
 * First round -> [-9,-567,0,23,78,70]   0 = array[(0+5)/2] Left and right swapped
 * Second round -> [-567,-9,0,23,78,70]  -9 = array[(0+1)/2] Recurse to the left
 * Third round -> [-567,-9,0,23,70,78]  70 = array[(3+8)/2] Recurse to the right
 * @author liuhongjie
 */
public class QuickSort {
    public static void main(String[] args) {
        int[] array = {-9, 78, 0, 23, -567, 70};
        quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }


    /**
     * @param array Sorting array
     * @param left  Left index
     * @param right Right index
     */
    private static void quickSort(int[] array, int left, int right) {
        int l = left; // Left moving pointer
        int r = right; // Right moving pointer
        int temp; // Temporary variable for swapping
        int pivot = array[(left + right) / 2]; // Pivot value

        while (l < r) { // Indicates there are elements that have not been traversed and compared yet

            while (array[l] < pivot) { // Find an element larger than the pivot from left to right
                l += 1; // Move the pointer to continue searching
            }

            while (array[r] > pivot) { // Find an element smaller than the pivot from right to left
                r -= 1; // Move the pointer to continue searching
            }

            if (l >= r) { // Indicates that the elements on the left and right sides of the pivot have been swapped
                break;
            }

            // Swap
            temp = array[l];
            array[l] = array[r];
            array[r] = temp;

            if (array[l] == pivot) { // Indicates the left side has been traversed
                r -= 1; // Move the r pointer forward. We don't move l backward because if we do, and r == l, then l+=1; will leave an element out, and it won't be sorted later.
            }
            if (array[r] == pivot) { // Indicates the right side has been traversed
                l += 1; // Move the l pointer backward. We don't move r forward because if we do, and r == l, then r-=1; will leave an element out, and it won't be sorted later.
            }
        }
        // Exiting the loop means this round of sorting is over
        if (l == r) { // Indicates the two pointers coincide
            l += 1; // Move the pointers apart to avoid infinite recursion. Move l backward.
            r -= 1; // Move r forward.
        }

        if (left < r) { // Indicates the left side hasn't been completely sorted, there are still elements
            quickSort(array, left, r); // Recursively call to sort the left side
        }
        if (l < right) { // The right side hasn't been completely sorted
            quickSort(array, l, right); // Recursively call to sort the right side
        }
    }
}
