#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {

            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0)); // initialize the board to all zeros
    if (solveNQueens(board, 0, n)) {
        cout << "A solution was found!" << endl;
        // print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No solution was found." << endl;
    }
    return 0;
}
