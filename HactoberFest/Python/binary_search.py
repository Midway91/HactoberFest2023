# This function finds an element in a sorted list.
def binary_search(list, target):
    # Initialize two pointers, low and high, to the beginning and end of the list.
    low = 0
    high = len(list) - 1

    # While low is less than or equal to high:
    while low <= high:
        # Calculate the middle index of the list.
        mid = (low + high) // 2

        # If the element at the middle index is equal to the target element, return the middle index.
        if list[mid] == target:
            return mid

        # Otherwise, if the element at the middle index is less than the target element, set low to mid + 1.
        elif list[mid] < target:
            low = mid + 1

        # Otherwise, set high to mid - 1.
        else:
            high = mid - 1

    # If low is greater than high, the target element is not in the list.
    return -1


# Example usage:
list = [1, 3, 5, 7, 9]
target = 5

# Find the index of the target element in the list.
index = binary_search(list, target)

# Print the index of the target element.
print("The index of the target element is", index)
