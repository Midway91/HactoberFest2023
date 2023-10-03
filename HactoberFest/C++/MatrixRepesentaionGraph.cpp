#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int edge = 6;
    vector<vector<int>> matrix(edge, vector<int>(edge));
    for (int i = 0; i < edge; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    for (int i = 0; i < edge - 1; i++)
    {
        for (int j = 0; j < edge - 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
