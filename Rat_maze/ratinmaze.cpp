#include <bits/stdc++.h>

using namespace std;

class Solution {
void sol(int i, int j, vector < vector < int >> & arr, int n, vector < string > & ans, string move,
	vector < vector < int >> & visited, int dir[], int djr[]) {
	//if we reach the last cell of the matrix. just add the current move to the list of answers (ans) and return from the function, effectively stopping any further exploration.
	if (i == n - 1 && j == n - 1) {
	ans.push_back(move);
	return;
	}
	//initialise a string direction which represents all the directions.
	string direction = "DLRU";
	for (int ind = 0; ind < 4; ind++) {
	//calculate the next row index based on the current i (row) and the di array, which holds values for direction changes.
	int nexti = i + dir[ind];
	//calculate the next column index based on the current j (column) and the dj array, which holds values for direction changes.
	int nextj = j + djr[ind];
	// to check whether is is valid to move to the next cell
	// make sure to check if the next cell has been visited before.
	
	if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] && arr[nexti][nextj] == 1) {
	//Also Mark the current cell as visited to prevent revisiting it during the same path exploration.
		visited[i][j] = 1;
		// Recursively call the solve function with the updated position , the updated path move(adding the current direction), and the updated state information.
		sol(nexti, nextj, arr, n, ans, move + direction[ind], visited, dir, djr);
		// Reset the current cell's visited status to 0 to allow backtracking(an essential step)
		visited[i][j] = 0;
	}
	}

}
public:
	vector < string > Path(vector < vector < int >> & m, int n) {
	//we intialise with vector to get all the required values.
	vector < string > ans;
	//for visited cell
	vector < vector < int >> visited(n, vector < int > (n, 0));
	int dir[] = {
		+1,
		0,
		0,
		-1
	};
	int djr[] = {
		0,
		-1,
		1,
		0
	};
	//if top-left corner of the grid is equal to 1 to verify if there is a valid starting point in the grid.
	if (m[0][0] == 1) sol(0, 0, m, n, ans, "", visited, dir, djr);
	return ans;
	}
};

int main() {
int n = 4;

vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
	
Solution obj;
vector < string > result = obj.Path(m, n);
if (result.size() == 0)
	cout << -1;
else
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
cout << endl;

return 0;
}
