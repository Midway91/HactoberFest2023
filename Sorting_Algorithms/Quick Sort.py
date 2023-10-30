# Creating a function to implement Quick Sort
def quick_sort(arr):

    # Base case: if the list has 1 or fewer elements, it's already sorted.
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]  # Choose a pivot element, often the middle element.

    # Partition the list into elements less than, equal to, and greater than the pivot.
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    # Recursively sort the left and right partitions and combine them with the middle elements.
    return quick_sort(left) + middle + quick_sort(right)


# Testing our implementation of Quick Sort
if __name__ == '__main__':
    List = [21, 12, 32, 1, 2, 34, 123, 32, 43, 54, 76, 21]

    # Print the original list.
    print("Original List:")
    print(List)

    # Sort the list using the quick_sort function and print the sorted list.
    sorted_list = quick_sort(List)
    print("Sorted List:")
    print(sorted_list)
