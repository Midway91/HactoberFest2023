// Problem Statement: Given an array of N integers, write a program to implement the Bubble Sorting algorithm.

// Examples:


//   Example 1 :
// Input: N = 5, array[] = {5,4,3,2,1}
// Output: 1,2,3,4,5
// Explanation: After sorting we get 1,2,3,4,5

//   Example 2:
// Input: N = 6, array[] = {13,46,24,52,20,9}
// Output: 9,13,20,24,46,52
// Explanation: After sorting we get 9,13,20,24,46,52



#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After sorting: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);
    return 0;

}
