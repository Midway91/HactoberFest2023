#include<bits/stdc++.h>
using namespace std;

// Function to perform topological sort
vector<int> topoSort(int V, vector<int> adj[])
{
    // Initialize an array to store the in-degrees of each node
    vector<int> indegree(V, 0);

    // Calculate the in-degrees for each node
    for(int i = 0; i < V; i++)
    {
        for(auto x: adj[i])
        {
            indegree[x]++;
        }
    }

    // Initialize a queue to perform BFS
    queue<int> q;

    // Add nodes with in-degree 0 to the queue
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Initialize a vector to store the topological order
    vector<int> topo;

    // Perform BFS
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // Reduce the in-degree of adjacent nodes and add them to the queue if in-degree becomes 0
        for(auto x: adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    return topo;
}    

int main() {
    int N1 = 5; // Number of nodes
    vector<int> adj1[N1] = {{1, 2}, {3}, {3, 4}, {}, {}};
    vector<int> res1 = topoSort(N1, adj1);

    // Print the topological order
    cout << "Topological Order : ";
    for(int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(V+E)
// Space Complexity: O(V)
