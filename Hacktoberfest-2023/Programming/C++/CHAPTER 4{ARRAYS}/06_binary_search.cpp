#include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Enter number to be searched in array:";
    cin >> x;
    int bin;
    bin = binarysearch(arr, n, x);
    if (bin == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element is found at position " << bin + 1;
    }
    return 0;
}
