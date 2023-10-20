#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 15; // Maximum number of cities

int N; // Number of cities
double dp[1 << MAX_N][MAX_N]; // DP table to store subproblem solutions
vector<vector<double>> distance; // Distance matrix

double tsp(int mask, int pos) {
    // Base case: if all cities have been visited, return the distance to the starting city (0)
    if (mask == (1 << N) - 1) {
        return distance[pos][0];
    }

    // If the subproblem solution already exists, return it
    if (dp[mask][pos] != -1.0) {
        return dp[mask][pos];
    }

    double minCost = DBL_MAX;

    // Try to visit all unvisited cities
    for (int next = 0; next < N; ++next) {
        if (!(mask & (1 << next))) {
            double newCost = distance[pos][next] + tsp(mask | (1 << next), next);
            minCost = min(minCost, newCost);
        }
    }

    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    // Input: Number of cities and distance matrix
    cin >> N;
    distance.assign(N, vector<double>(N, 0.0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> distance[i][j];
        }
    }

    // Initialize the DP table
    for (int i = 0; i < (1 << MAX_N); ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            dp[i][j] = -1.0;
        }
    }

    // Start from the first city (city 0)
    double shortestPath = tsp(1, 0); // The starting mask is 1, and the starting position is 0

    cout << "Shortest Path Length: " << shortestPath << endl;

    return 0;
}
