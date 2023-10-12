#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int medianOfMatrix(vector<vector<int>> &mat, int R, int C)
{
    int min = mat[0][0], max = mat[0][C - 1];
    for (int i = 1; i < R; i++)
    {
        if (mat[i][0] < min)
        {
            min = mat[i][0];
        }
        if (mat[i][C - 1] > max)
        {
            max = mat[i][C - 1];
        }
    }
    int medianPos = (R * C + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;
        for (int i = 0; i < R; i++)
        {
            midPos += distance(mat[i].begin(), upper_bound(mat[i].begin(), mat[i].end(), mid));
        }
        if (midPos < medianPos)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}

int main()
{
    int m, n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;

    vector<vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int element;
            cin >> element;
            v.push_back(element);
        }
        mat.push_back(v);
    }

    int result = medianOfMatrix(mat, m, n);
    cout << "Median of the matrix is: " << result << endl;
    return 0;
}
