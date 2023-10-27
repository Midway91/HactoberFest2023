#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Increasing Subsequence
int longestIncreasingSequence(int n, int arr[]) {
    // lis array to store the length of LIS ending at each index
    int lis[n];

    // Initialize lis array with 1, as the minimum length of LIS at any index is 1 (the element itself)
    lis[0] = 1;

    // Loop through each element in the array
    for (int i = 1; i < n; i++) {
        lis[i] = 1; // Initialize LIS length for the current index

        // Check previous elements to find the LIS
        for (int j = 0; j < i; j++) {
            // If the current element is greater than the previous element
            // and adding it to the LIS ending at the previous element gives a longer LIS
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Return the maximum value in the lis array, which represents the length of the longest increasing subsequence
    return *max_element(lis, lis + n);
}

int main() {
    int n;
    cout << "Enter the number of terms in the array:" << "\n";
    cin >> n;

    int array[n];
    cout << "Enter elements:" << "\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << "th Element:" << "\n";
        cin >> array[i];
    }

    // Call the function to find the length of the Longest Increasing Subsequence
    int length = longestIncreasingSequence(n, array);

    cout << "Length of the Longest Increasing Subsequence: " << length;

    return 0;
}
