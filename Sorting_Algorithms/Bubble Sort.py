# Creating Function To Implement Bubble Sort Using Iteration

def bubble_sort(arr):
    arr.sort()
    l = len(arr)            # Get the length of the input list.
    a = l - 1               

    for i in range(l):
        for j in range(a):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]     # Swapping The Adjacent Elements.

        a = a - 1            # Decrement the maximum index to mark one more element as sorted.

    return arr

if __name__ == '__main__':
    List = [31, 25, 19, 90, 4, 67, 3, 12, 68]  # unsorted list

    # Print the original list.
    print("Original List:")
    print(List)

    # Sort the list using the bubble_sort function and print the sorted list.
    sorted_list = bubble_sort(List)
    print("Sorted List:")
    print(sorted_list)
