def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1  # Return -1 if the target is not in the array

# Example usage:
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
target = 5
result = binary_search(my_list, target)

if result != -1:
    print(f"Target {target} found at index {result}")
else:
    print(f"Target {target} not found in the array")
