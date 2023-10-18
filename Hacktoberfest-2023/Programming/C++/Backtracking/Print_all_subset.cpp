#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& inputArray, vector<vector<int> >& resultantSubsets,
				vector<int>& currentSubset, int currentElementIndex)
{
	resultantSubsets.push_back(currentSubset);
	for (int i = currentElementIndex; i < inputArray.size(); i++) {
		currentSubset.push_back(inputArray[i]);
		generateSubsets(inputArray, resultantSubsets, currentSubset, i + 1);
		currentSubset.pop_back();
	}
}

vector<vector<int> > findSubsets(vector<int>& inputArray)
{
	vector<int> currentSubset;
	vector<vector<int> > resultantSubsets;
	int currentElementIndex = 0;
	generateSubsets(inputArray, resultantSubsets, currentSubset, currentElementIndex);
	return resultantSubsets;
}

int main()
{
	vector<int> inputArray = { 1, 2, 3 };
	vector<vector<int> > resultantSubsets = findSubsets(inputArray);

	for (int i = 0; i < resultantSubsets.size(); i++) {
		for (int j = 0; j < resultantSubsets[i].size(); j++)
			cout << resultantSubsets[i][j] << " ";
		cout << endl;
	}
	return 0;
}