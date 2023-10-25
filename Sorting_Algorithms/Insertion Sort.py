# Creating Function To Implement Insertion Sort Using Iteration

def insertion_sort(arr):    

    for i in range(1, len(arr)):
        current_element = arr[i]             
        j = i - 1

        while j >= 0 and arr[j] > current_element:
            arr[j + 1] = arr[j]
            j = j - 1

        arr[j + 1] = current_element

    return arr


if __name__ == '__main__':

    List = [32, 3, 2, 1, 112, 12, 31, 21, 42, 32]  # unsorted list

    # Print the original list.
    print("Original List:")
    print(List)

    # Sort the list using the insertion-sort function and print the sorted list.
    sorted_list = insertion_sort(List)
    print("Sorted List:")
    print(sorted_list)
