#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//This is a solution for leetcode based c++ problem on the famed Nqueens backtracking problem

class Solution {
public:
    bool isSafe(vector<string>&r,int row,int col,int n)
    {
        for(int i=0;i<col;i++)
        {
            if(r[row][i]=='Q')
               return false;
        }
        for(int i=row,j=col;i>=0 && j>=0; i--,j--)
        {
            if(r[i][j]=='Q')
               return false;
        }
        for(int i=row,j=col;i<n && j>=0;i++,j--)
        {
            if(r[i][j]=='Q')
               return false;
        }
        return true;
    }
    void boardSolveUtil(vector<vector<string>>&board,int col,int n,vector<string>&r)
    {
        int i;
        if(col>=n)
        {
            board.push_back(r);
            return;
        }
        for(i=0;i<n;i++)
        {
            if(isSafe(r,i,col,n))
            {
                r[i][col]='Q';
                boardSolveUtil(board,col+1,n,r);
                r[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>board;
        string temp="";
        for(int i=0;i<n;i++)
           temp+='.';
        vector<string>r(n,temp);
        boardSolveUtil(board,0,n,r);
        return board;
        
        
        
    }
};
int main()
{
    Solution obj; 
    vector<vector<string>>board=obj.solveNQueens(4);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
          cout<<board[i][j]<<" ";
        cout<<endl;
    }
}


//i/o format:
/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/