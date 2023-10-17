# Define the Bubble Sort function
def bubble_sort(arr):
    """
    Sorts a list of numbers in ascending order using the Bubble Sort algorithm.

    Args:
        arr (list): The list of numbers to be sorted.

    Returns:
        None. The input list is sorted in-place.
    """
    n = len(arr)  # Get the number of elements in the list

    # Outer loop: Iterate through all elements in the list
    for i in range(n):
        # Flag to optimize by stopping the algorithm if no two elements are swapped in a pass
        swapped = False

        # Inner loop: Compare and swap adjacent elements
        # After each iteration of the inner loop, the largest unsorted element moves to the end
        for j in range(0, n - i - 1):
            # Compare adjacent elements
            if arr[j] > arr[j + 1]:
                # Swap the elements if they are in the wrong order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True  # Set the swapped flag to True

        # If no two elements were swapped in the inner loop, the list is already sorted
        if not swapped:
            break

# Input from the user
try:
    input_str = input("Enter a list of numbers separated by spaces: ")
    input_list = [int(x) for x in input_str.split()]  # Convert input to a list of integers

    # Call the Bubble Sort function to sort the input list
    bubble_sort(input_list)

    # Display the sorted list
    print("Sorted list:", input_list)
except ValueError:
    print("Invalid input. Please enter a list of numbers separated by spaces.")
