#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    int bucketCount = range / 10 + 1; // Divide the range into buckets, e.g., 10 elements per bucket.
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int i = 0; i < arr.size(); i++) {
        int bucketIndex = (arr[i] - minVal) / 10;
        buckets[bucketIndex].push_back(arr[i]);
    }

    arr.clear();

    for (int i = 0; i < bucketCount; i++) {
        std::sort(buckets[i].begin(), buckets[i].end()); // Sort each bucket.
        for (int j = 0; j < buckets[i].size(); j++) {
            arr.push_back(buckets[i][j]);
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the elements of the array "<<i<<" : ";    
        std::cin >> arr[i];
    }

    bucketSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
