def linear_search(arr, target):
    for index, item in enumerate(arr):
        if item == target:
            return index  # Return the index of the target element if found
    return -1  # Return -1 if the target element is not in the list

# Example usage
arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
target = 9

result = linear_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the list.")
