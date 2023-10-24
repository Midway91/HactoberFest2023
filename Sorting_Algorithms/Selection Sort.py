# Function to implement Selection Sort

def selection_sort(arr):
    l = len(arr)
    
    # Iterate through the entire list.
    for i in range(l):

        for j in range(i + 1, l):
            
            # Check if the current element is greater than the element at the next position.            
            if arr[i] > arr[j]:
                # Swap the elements if they are out of order.
                arr[i], arr[j] = arr[j], arr[i]
    
    return arr



if __name__ == '__main__':
    List = [1, 5, 2, 90, 4, 67, 23, 12, 68]

    # Print the original list.
    print("Original List:")
    print(List)

    # Sort the list using the selection_sort function and print the sorted list.
    sorted_list = selection_sort(List)
    print("Sorted List:")
    print(sorted_list)
