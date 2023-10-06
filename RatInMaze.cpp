#include <iostream>
using namespace std;

// Maze size
#define N 4

// Function to print the solution matrix
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if x, y is a valid move
bool isSafe(int maze[N][N], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the Rat in a Maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // If the rat reaches the destination
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if x, y is a valid move
    if (isSafe(maze, x, y))
    {
        // Mark x, y as part of the solution path
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Move down
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // If no valid moves, backtrack and mark this cell as not part of the solution path
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Main function to solve the Rat in a Maze problem
void solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0}};

    if (solveMazeUtil(maze, 0, 0, sol))
        printSolution(sol);
    else
        cout << "Solution doesn't exist." << endl;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}
