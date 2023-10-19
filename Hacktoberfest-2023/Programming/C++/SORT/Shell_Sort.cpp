// For detailed understanding, Steps are written at the Bottom of Code

#include <iostream>
#include <vector>

using namespace std;

// Function of Shell Sort
void shellSort(vector<int> &arr)
{
    int n = arr.size();

    // Starting with a large gap and reducing it until it becomes 1
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Performing insertion sort for elements at the gap intervals
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // Shift elements that are greater than temp by gap positions
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            // Placing temp in its correct position
            arr[j] = temp;
        }
    }
}

int main()
{
    // Given Vector Array
    vector<int> arr = {73, 33, 31, 40, 8, 12, 17, 34, 65};

    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    shellSort(arr);

    cout << "\nSorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}

// What is Shell Sort Algorithm?
//  Shell Sort works by gradually sorting elements that are far apart, and then reducing the gap between elements to achieve a more refined sorting until the gap becomes 1, which is essentially an insertion sort. This combination of sorting with large gaps and smaller gaps results in a more efficient sorting algorithm than a simple insertion sort for larger datasets.

// How does the Shell Sort Algorithm works?

// 1. Here, 'shellSort' is the main function that performs the Shell Sort algorithm on a vector of integers.
// 2. It takes the input array by reference to modify it in place.
// 3. The variable n stores the size of the array.
// 4. The outer loop iterates over decreasing gap sizes starting with n/2 and reducing it by half in each iteration until 'gap' becomes 1.
// 5. The inner loop performs an insertion sort for elements at gap intervals.
// 6. For each element at index i, it is compared and swapped with elements that are 'gap' positions before it, until the correct position is found.
// 7. The elements are shifted by 'gap' positions until the element 'temp' is placed in its correct sorted position.
// 8. The main function demonstrates the sorting by initializing a vector with some values, calling shellSort, and then printing the sorted array.
