#include <iostream>

int findOddOccurrence(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {4, 3, 2, 4, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int oddOccurrence = findOddOccurrence(arr, n);
    std::cout << "The number with odd occurrence is: " << oddOccurrence << std::endl;
    
    return 0;
}
