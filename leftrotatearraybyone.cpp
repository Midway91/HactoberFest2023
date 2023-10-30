#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& vec, int d)
{
	// Base case
	if (d == 0)
		return;

	// Push first d elements from the beginning
	// to the end and remove those elements
	
	for (int i = 0; i < d; i++)
	{
		// adding first element at
		// the end of vector
		vec.push_back(vec[0]); 
	
		// removing first element
		vec.erase(vec.begin()); 
	}

	// Print the rotated array
	for (int i = 0; i < vec.size(); i++) 
	{
		cout << vec[i] << " ";
	}
}

// Driver code
int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	int n = vec.size();
	int d = 2;

	// Function call
	rotate(vec, d % n);

	return 0;
}
