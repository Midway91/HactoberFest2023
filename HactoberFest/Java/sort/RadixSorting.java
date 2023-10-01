package sort;

import java.util.Arrays;

/**
 * Radix Sort (Time Complexity O(1))
 * <p>
 * Implementation Logic:
 * 1. First, determine the total number of swaps needed.
 * 1.1 The number of swaps is the number of digits in the largest element in the array.
 * 2. Define a two-dimensional array to store the elements in the corresponding position in the array based on each corresponding digit. Define a one-dimensional array to record the number of elements in the bucket in the two-dimensional array, which controls the number of iterations when taking data.
 * 3. Place the elements that have been completely traversed and arranged in the original array one by one.
 * 4. Repeat steps 2 and 3 for the number of digits in the largest number found in step 1 to complete the sorting.
 * 5. Note -> When taking data from the two-dimensional array and placing it in the original array, the index array at this position needs to be set to 0 to prevent errors when taking data next time.
 * <p>
 * Deduction Process:
 * First Round:
 * Two-dimensional array (bucket) -> One-dimensional array (index) -> Put back into the original array ->
 * (Details omitted for brevity)
 * ---------------------------------------------------------------------------------
 * Second Round:
 * (Details omitted for brevity)
 * ---------------------------------------------------------------------------------
 * Third Round:
 * (Details omitted for brevity)
 *
 * @author liuhongjie
 */
public class RadixSorting {
    public static void main(String[] args) {

        int[] array = {53, 3, 542, 748, 14, 214};
        radixSorting(array);
        System.out.println(0 % 10);
        System.out.println(Arrays.toString(array));

    }

    private static void radixSorting(int[] array) {

        // Find the maximum element
        int maxNum = array[0];
        for (int i = 0; i < array.length - 1; i++) {
            if (maxNum < array[i]) {
                maxNum = array[i];
            }
        }

        int max = (String.valueOf(maxNum)).length(); // Get the length of the maximum number

        int[][] bucket = new int[10][array.length]; // Create a two-dimensional array

        int[] bucketEnm = new int[10]; // Create a one-dimensional array as an index counter for the two-dimensional array

        // This loop controls the total number of rounds, which is the length of the maximum element in the array[]; n: calculates the units, tens, hundreds... digits of the elements in each round
        for (int i = 0, n = 1; i < max; i++, n *= 10) {

            for (int value : array) { // Traverse array[] array
                int enmDate = value / n % 10; // Take the unit or ten or hundred... (determined by the loop above) digits of the number
                bucket[enmDate][bucketEnm[enmDate]] = value; // Put the number into the corresponding bucket (two-dimensional array bucket)
                bucketEnm[enmDate]++; // Index counter +1 -> Indicates that there are two or more elements with the same corresponding digits
            }

            int index = 0; // Temporary variable used to record the index of the element to be overwritten in the array[] array
            for (int j = 0; j < bucketEnm.length; j++) { // Traverse the index array

                if (bucketEnm[j] != 0) { // Find the non-zero bucket position

                    for (int k = 0; k < bucketEnm[j]; k++) { // According to the index counter one-dimensional array

                        array[index++] = bucket[j][k]; // Place the elements in the two-dimensional array bucket into the original array in order (overwrite)
                    }
                }
                bucketEnm[j] = 0; // To avoid repeated counting in the next loop, set the index array element to 0 after taking it out

            }
        }
    }
}
