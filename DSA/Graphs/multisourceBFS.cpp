#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Given a matrix of 1s and 0s. Return a distance matrix which contains distances of each
// index from the neareset 1

// Approach 1: for each index, traverse whole matrix and get nearest distance from 1
// T.C = 0(nxmxnxm) = 0(n^2 x m^2)

// Efficient approach: To use multisource BFS
// where souces are all 1s which are at level 0
// we perform BFS and move into each level where level represents distance

vector<vector<int>> getDistance(vector<vector<int>> grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dis(r, vector<int>(c, -1));

    // Traversing the matrix and storing 1s position
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    // Multisource BFS
    int s;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int row, col, dr, dc;
    while (!q.empty())
    {
        s = q.size();
        for (int i = 0; i < s; i++)
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                dr = row + dx[k];
                dc = col + dy[k];
                if (dr < 0 || dr >= r || dc < 0 || dc >= c || dis[dr][dc] != -1)
                    continue;
                q.push({dr, dc});
                dis[dr][dc] = dis[row][col] + 1;
            }
        }
    }
    return dis;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}};
    getDistance(matrix);

    return 0;
}
