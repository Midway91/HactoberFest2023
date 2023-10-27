#include <iostream>
#include <vector>
using namespace std;
void maxMin(vector<int> vec, int n, int& bingo,
			int& nextBingo)
{
	for (int i = 1; i < n; bingo = min(bingo, vec[i]), nextBingo = max(nextBingo, vec[i]), i++)
		;
}

void bingoSort(vector<int>& vec, int n)
{
	int bingo = vec[0];
	int nextBingo = vec[0];
	maxMin(vec, n, bingo, nextBingo);
	int largestEle = nextBingo;
	int nextElePos = 0;
	while (bingo < nextBingo) {
		// Will keep the track of the element position to
		// shifted to their correct position
		int startPos = nextElePos;
		for (int i = startPos; i < n; i++) {
			if (vec[i] == bingo) {
				swap(vec[i], vec[nextElePos]);
				nextElePos = nextElePos + 1;
			}
		
			else if (vec[i] < nextBingo)
				nextBingo = vec[i];
		}
		bingo = nextBingo;
		nextBingo = largestEle;
	}
}

void printArray(vector<int> arr, int n)
{
	cout << "Sorted Array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> arr = { 5, 4, 8, 5, 4, 8, 5, 4, 4, 4 };
	bingoSort(arr, arr.size());
	printArray(arr, arr.size());

	vector<int> arr2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	bingoSort(arr2, arr2.size());
	printArray(arr2, arr2.size());

	vector<int> arr3 = { 0, 1, 0, 1, 0, 1 };
	bingoSort(arr3, arr3.size());
	printArray(arr3, arr3.size());
	return 0;
}
