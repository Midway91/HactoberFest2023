#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

int main() {
    //int arr[] = {2, 1, 3, 8, 5, 7, 9, 4, 6, 10}; //change number
    //int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> arr;

    int n;
    //size of arry;
    cin>>n;

    //user input arry
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    std::cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    bubbleSort(arr, n);
    
    std::cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
