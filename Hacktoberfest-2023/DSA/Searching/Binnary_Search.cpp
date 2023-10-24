#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int arr[], int key, int n)
{
	int s = 0, e = n - 1;
	int mid = s + (e - s) / 2;
	while (s <= e)
	{
		if (arr[mid] == key)
		{
			return 1;
		}
		else if (arr[mid] < key)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
		mid = s + (e - s) / 2;
	}
	return 0;
}

int main()
{
	int n;
	cout << "Enter the number of elements:" << endl;
	cin >> n;
	int arr[10000];
	cout << "Enter the array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int key;
	cout << "Enter the element to find:" << endl;
	cin >> key;
	// sorting the array
	sort(arr, arr + n);
	bool isPresent = binarySearch(arr, key, n);
	if (isPresent)
	{
		cout << "Element is Present" << endl;
	}
	else
	{
		cout << "Element is not Present" << endl;
	}
	return 0;
}