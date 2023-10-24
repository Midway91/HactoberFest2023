#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    bool isSorted = true;
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            isSorted = false;
            break;
        }
    }

    if(isSorted) {
        cout << "The array is sorted in ascending order." << endl;
    } else {
        cout << "The array is not sorted in ascending order." << endl;
    }

    return 0;
}
