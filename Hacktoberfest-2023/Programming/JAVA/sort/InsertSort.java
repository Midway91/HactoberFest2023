package sort;

import java.util.Arrays;

/**
 * Insertion Sort
 * Time Complexity -> O(nlogN)
 * <p>
 * Idea: See Interview Related ▸ Data Structures and Algorithms
 * Mind Map: See Interview Related ▸ Data Structures and Algorithms ▸ Algorithms ▸ Eight Major Sorting Algorithms
 * Deduction Process (Ascending Order):
 * Initial   -> [3,2,9,1,5] Sorted List:[3] Unsorted List:[2,9,1,5]
 * First Round -> [2,3,9,1,5] Sorted List:[2,3] Unsorted List:[9,1,5]
 * Second Round -> [2,3,9,1,5] Sorted List:[2,3,9] Unsorted List:[1,5]
 * Third Round -> [1,2,3,9,5] Sorted List:[1,2,3,9] Unsorted List:[5]
 * Fourth Round -> [1,2,3,5,9] Sorted List:[1,2,3,5,9] Unsorted List: None
 * Conclusion:
 * Number of Sorts: n-1 times
 * Sorted List: First Round:1   Second Round:1+1   nth Round:n
 * Unsorted List: First Round:n-1 Second Round:n-1-1 nth Round:0
 * @author liuhongjie
 */
public class InsertSort {
    public static void main(String[] args) {

        int[] array = {9, 2, 3, 1, 5};
        InsertSort.insertSort(array);

    }

    private static void insertSort(int[] array) {
        int insert; // The first element in the unsorted list
        int insertIndex; // Index of the last element in the sorted list
        for (int i = 1; i < array.length; i++) { // Each loop increases the sorted list by 1 and decreases the unsorted list by 1. Loop array.length -1 times

            insert = array[i]; // The first element in the unsorted list
            insertIndex = i - 1; // Index of the last element in the sorted list

            // insertIndex >= 0 prevents index out of bounds, insert < array[insertIndex] means the first element in the unsorted list is smaller than the last element in the sorted list, so they need to swap positions
            while (insertIndex >= 0 && insert < array[insertIndex]) {
                array[insertIndex + 1] = array[insertIndex]; // Overwrite the first element in the unsorted list
                insertIndex--; // Decrease index by 1 to find the position in the sorted list where it's smaller than insert
            }

            if (!(insert == array[insertIndex + 1])) { // Optimization: If insert (from the unsorted list) is already in the correct position, no need to swap
                array[insertIndex + 1] = insert; // Overwrite the element after finding the correct position
            }
        }
        System.out.println(Arrays.toString(array));
    }
}
