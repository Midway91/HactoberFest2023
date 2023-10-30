//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node, vector<int> adj[], vector<bool>&visited, vector<bool>&disvisited){
        visited[node] = true;
        disvisited[node] = true;
        for(auto i: adj[node]){
            if(!visited[i]){
                if(checkCycle(i, adj, visited, disvisited))
                    return true;
            }
            else if(disvisited[i])
                return true;
        }
        disvisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> disvisited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkCycle(i, adj, visited, disvisited))
                    return true;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends