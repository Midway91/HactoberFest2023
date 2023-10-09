class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
{
    vector<int> ans;
    for (int j = 0; j < m; j++) // first column to last column
    {
        ans.push_back(matrix[0][j]); // [first row] [j]
    }
    for (int i = 1; i < n - 1; i++) // second row to second last row
    {
        ans.push_back(matrix[i][m - 1]); // [i] [last column]
    }
    if (n == 1)
    {
        return ans;
    }
    for (int j = m - 1; j >= 0; j--) // last column to first column
    {
        ans.push_back(matrix[n - 1][j]); // [last row] [j]
    }
    if (m == 1)
    {
        return ans;
    }
    for (int i = n - 2; i >= 1; i--) // second last row to second row
    {
        ans.push_back(matrix[i][0]); // [i] [first column]
    }
    return ans;
}
};
