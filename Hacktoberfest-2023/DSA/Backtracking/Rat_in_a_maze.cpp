#include <iostream>
#include <vector>

using namespace std;

const int N = 4; // The size of the maze (N x N)

// Function to print the solution matrix
void printSolution(const vector<vector<int>>& solution) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the current cell is a valid move
bool isSafe(const vector<vector<int>>& maze, int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the Rat in a Maze problem
bool solveMazeUtil(const vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    // If the rat reaches the exit, we have a solution
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if the current cell is a valid move
    if (isSafe(maze, x, y)) {
        // Mark the cell as part of the solution path
        solution[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, solution))
            return true;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, solution))
            return true;

        // If no valid move is found, backtrack and mark the cell as not part of the solution path
        solution[x][y] = 0;
    }

    return false;
}

// Main function to solve the Rat in a Maze problem
void solveMaze(const vector<vector<int>>& maze) {
    vector<vector<int>> solution(N, vector<int>(N, 0)); // Create a solution matrix

    if (solveMazeUtil(maze, 0, 0, solution)) {
        cout << "Solution exists. Path taken by the rat:" << endl;
        printSolution(solution);
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
