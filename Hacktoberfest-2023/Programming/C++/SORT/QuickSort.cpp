#include<iostream>
using namespace std;


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main()
{
	int N;
    cout<<"ENTER THE SIZE OF THE ARRAY : ";
    cin>>N;
    int arr[N];
    cout<<"ENTER THE ELEMENTS OF THE ARRAY : "<<endl;
    for(int j=0;j<N;j++)
        cin>>arr[j];
	quickSort(arr, 0, N - 1);
	cout<<"SORTED ARRAY : "<<endl;
	for (int i = 0; i < N; i++)
		cout<<arr[i]<<" ";
	return 0;
}
