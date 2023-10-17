//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void revDfs(int node,unordered_map<int,bool> &vis,vector<int> transpose[]) {
        vis[node] = true;
        
        for(auto nbr:transpose[node]) {
            if(!vis[nbr])
            revDfs(nbr,vis,transpose);
        }
    }
    
    void topoSort(int node,unordered_map<int,bool> &vis,stack<int> &st,vector<vector<int>> &adj) {
        vis[node] = true;
        
        for(auto nbr:adj[node]) {
            if(!vis[nbr])
            topoSort(nbr,vis,st,adj);
        }
        st.push(node);
    }
    
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        unordered_map<int,bool> vis;
        stack<int> st;
        
        for(int i = 0;i<V;i++) {
            if(!vis[i])
                topoSort(i,vis,st,adj);
        }
        
        vector<int> transpose[V];
        int count = 0;
        
        for(int i = 0;i<V;i++) {
            vis[i] = 0;
            for(auto nbr:adj[i])
            transpose[nbr].push_back(i);
        }
        
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(!vis[top]) {
                count++;
                revDfs(top,vis,transpose);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends