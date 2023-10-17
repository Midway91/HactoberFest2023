//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        vector<bool> vis(V,false);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        key[0] = 0;
        for(int i = 0;i<V;i++) {
            int mini = INT_MAX;
            int u;
            for(int j = 0;j<V;j++) {
                if(vis[j] == false and key[j] < mini) {
                    mini = key[j];
                    u = j;
                }
            }
            
            vis[u] = true;
            for(auto it:adj[u]) {
                int neighbour = it[0];
                int weight = it[1];
                
                if(key[neighbour] > weight and vis[neighbour] == false)
                {
                    parent[neighbour] = u;
                    key[neighbour] = weight;
                }
            }
        }
        for(int i = 1;i<V;i++ ){
            ans+=key[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends