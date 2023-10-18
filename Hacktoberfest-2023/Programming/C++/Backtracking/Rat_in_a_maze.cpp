// Codestudio: rat in a maze

#include <bits/stdc++.h>
using namespace std;

bool isSafePath(int newRow, int newCol, int n, vector<vector<int>> &arr, vector<vector<bool>> &vis)
{
    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && arr[newRow][newCol] == 1 && vis[newRow][newCol] != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void searchMaze(int row, int col, int n, string path, vector<vector<int>> &arr, vector<string> &ans, vector<vector<bool>> &vis)
{
    // base case
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Movements: D L R U

    // mark path as visited
    vis[row][col] = 1;

    // Down
    if (isSafePath(row + 1, col, n, arr, vis))
    {
        searchMaze(row + 1, col, n, path + 'D', arr, ans, vis);
    }

    // Left
    if (isSafePath(row, col - 1, n, arr, vis))
    {
        searchMaze(row, col - 1, n, path + 'L', arr, ans, vis);
    }

    // Right
    if (isSafePath(row, col + 1, n, arr, vis))
    {
        searchMaze(row, col + 1, n, path + 'R', arr, ans, vis);
    }

    // Up
    if (isSafePath(row - 1, col, n, arr, vis))
    {
        searchMaze(row - 1, col, n, path + 'U', arr, ans, vis);
    }

    // unmark path on back track
    vis[row][col] = 0;
}

void solve(int n, vector<vector<int>> &arr)
{
    vector<string> ans;

    if (arr[0][0] == 0)
    {
        cout << "";
        return;
    }

    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));

    searchMaze(0, 0, n, path, arr, ans, visited);

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}

int main()
{

    int n = 3;
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    solve(n, arr);

    return 0;
}