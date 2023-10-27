# Creating a function to implement Merge Sort
def merge_sort(arr):
    # Base case: if the list has 1 or fewer elements, it's already sorted.
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    # Recursively split the list into left and right halves and sort them.
    left_arr = merge_sort(arr[:mid])
    right_arr = merge_sort(arr[mid:])

    # Merge the sorted left and right halves.
    return merge(left_arr, right_arr)


# Helper function for merging two lists in order.
def merge(left, right):
    result = []
    left_index, right_index = 0, 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            result.append(left[left_index])
            left_index += 1
        elif left[left_index] > right[right_index]:
            result.append(right[right_index])
            right_index += 1
        else:
            # Handle equal elements by adding both to the result.
            result.extend([left[left_index], right[right_index]])
            left_index += 1
            right_index += 1

    # Extend the result with any remaining elements from the left and right lists.
    result.extend(left[left_index:])
    result.extend(right[right_index:])

    return result


# main 
if __name__ == '__main__':
    List = [1, 5, 90, 2, 90, 4, 67, 23, 12, 12, 68]  # Unsorted List

    # Print the original list.
    print("Original List:")
    print(List)

    # Sort the list using the merge_sort function and print the sorted list.
    sorted_list = merge_sort(List)
    print("Sorted List:")
    print(sorted_list)
