#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
