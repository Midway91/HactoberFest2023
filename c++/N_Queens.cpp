#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<vector<int>>> v;

/*
Give input n = no. of queens...
Output --> All Combinations of positions of n queens so that no queen can attack other..
*/

bool is_safe(int row, int col){

    int x = row, y = col;
    //check for same row
    while(y>=0){
        if(board[x][y]==1){return false;}
        y--;
    }

    int xx = row, yy = col;
    //check for diagonal
    while(xx>=0 && yy>=0){
        if(board[xx][yy]==1){return false;}
        xx--; yy--;
    }

    int a = row, b = col;
    //check for diagonal
    while(a<n && b>=0){
        if(board[a][b]==1){return false;}
        a++; b--;
    }

    return true;

}



void solve(int col, int n){

    // base case (if every col is filled)
    if(col == n){
        v.push_back(board);
        return;
    }

    //put queen in every row of diff col..
    for(int row = 0; row<n; row++){
        if(is_safe(row,col)){

            // if placing queen is safe
            board[row][col] = 1;

            solve(col+1, n);

            //backtrack
            board[row][col] = 0;
        }
    }


}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++){
        vector<int> temp(n, 0);
        board.push_back(temp);
    }

    solve(0, n);
    cout<<v.size()<<"\n";

    for(auto b : v){
        for(auto vv : b){
            for(int g : vv){
                cout<<g<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }


}
