// Hamiltonian Path ( Using Dynamic Programming )

#include <bits/stdc++.h>
using namespace std;
const int N = 5;
bool Hamiltonian_path(
	vector<vector<int> >& adj, int N)
{
	int dp[N][(1 << N)];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++)
		dp[i][(1 << i)] = true;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < N; k++) {

					if (i & (1 << k)
						&& adj[k][j]
						&& j != k
						&& dp[k][i ^ (1 << j)]) {
						dp[j][i] = true;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {		
		if (dp[i][(1 << N) - 1])
			return true;
	}
	return false;
}

int main()
{
	vector<vector<int> > adj = { { 0, 1, 1, 1, 0 },
								{ 1, 0, 1, 0, 1 },
								{ 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 0, 0 } };
	int N = adj.size();
	if (Hamiltonian_path(adj, N))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
