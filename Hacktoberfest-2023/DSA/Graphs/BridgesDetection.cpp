//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int c,int d,int node,vector<int> adj[],vector<bool> &vis) {
        vis[node] = true;
        for(auto neighbour:adj[node]) {
            if(vis[neighbour] == false and (c!=node or d!=neighbour))
                dfs(c,d,neighbour,adj,vis);
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> vis(V,false);
       
            dfs(c,d,c,adj,vis);
        
        if(vis[d] == true)
        return false;
        return true;
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends