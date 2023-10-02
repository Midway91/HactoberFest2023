#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr, int target) {
  vector<vector<int>> triplets;

  // Sort the array.
  sort(arr.begin(), arr.end());

  // Iterate over the array.
  for (int i = 0; i < arr.size() - 2; i++) {
    // Initialize two pointers.
    int left = i + 1;
    int right = arr.size() - 1;

    // While the pointers are not at the same index.
    while (left < right) {
      // Calculate the sum of the three elements.
      int sum = arr[i] + arr[left] + arr[right];

      // If the sum is equal to the target value, add the triplet to the result.
      if (sum == target) {
        triplets.push_back({arr[i], arr[left], arr[right]});

        // Move the left pointer to the next element, as we have already found a valid triplet.
        left++;
      } else if (sum < target) {
        // Move the left pointer to the next element, as the sum is too small.
        left++;
      } else {
        // Move the right pointer to the previous element, as the sum is too large.
        right--;
      }
    }
  }

  return triplets;
}

int main() {
  vector<int> arr = {-1, 0, 1, 2, -1, -4};
  int target = 0;

  vector<vector<int>> triplets = threeSum(arr, target);

  for (vector<int> triplet : triplets) {
    for (int element : triplet) {
      cout << element << " ";
    }
    cout << endl;
  }

  return 0;
}
