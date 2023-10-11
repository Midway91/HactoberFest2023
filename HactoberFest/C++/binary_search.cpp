// Binary Search in C++

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high)
{

    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    
    cout << "Enter the size of array : ";
    cin >> n;
   
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int x;
    cout << "enter the key you want to search : ";
    cin >> x;
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        cout << "Not Found" << endl;
    else
        cout << "Element is found at index " << result << endl;

    return 0;
}