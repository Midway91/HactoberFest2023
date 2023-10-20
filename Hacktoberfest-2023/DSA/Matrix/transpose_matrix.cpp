// Leetcode Question 867 Solution
class Solution{
public:
    vector<vector<int>>transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>transposed(n, vector<int>(m));
        
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};
