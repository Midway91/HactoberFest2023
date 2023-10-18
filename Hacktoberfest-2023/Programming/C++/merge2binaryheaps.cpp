// MERGING OF TWO BINARY MAX HEAPS 

#include <bits/stdc++.h>
using namespace std;
void maxHeapify(int arr[], int N, int idx)
{
	if (idx >= N)
		return;
	int l = 2 * idx + 1;
	int r = 2 * idx + 2;
	int max = idx;
	if (l < N && arr[l] > arr[idx])
		max = l;
	if (r < N && arr[r] > arr[max])
		max = r;
	if (max != idx) {
		swap(arr[max], arr[idx]);
		maxHeapify(arr, N, max);
	}
}
void buildMaxHeap(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		maxHeapify(arr, N, i);
}
void mergeHeaps(int merged[], int a[], int b[], int N,
				int M)
{
	for (int i = 0; i < N; i++)
		merged[i] = a[i];
	for (int i = 0; i < M; i++)
		merged[N + i] = b[i];
	buildMaxHeap(merged, N + M);
}
int main()
{
	int a[] = { 10, 5, 6, 2 };
	int b[] = { 12, 7, 9 };
	int N = sizeof(a) / sizeof(a[0]);
	int M = sizeof(b) / sizeof(b[0]);
	int merged[N + M];
	mergeHeaps(merged, a, b, N, M);
	for (int i = 0; i < N + M; i++)
		cout << merged[i] << " ";
	return 0;
}
