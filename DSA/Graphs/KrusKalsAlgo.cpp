//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
 int find(vector<int>&parent, int x)
  {
      if(x== parent[x]) return x;
      parent[x] = find(parent, parent[x]);
      return parent[x];
  }

  void Union(vector<int>&parent, vector<int>&rank, int x, int y)
  {
    
    int x_rep = find(parent, x);
    int y_rep = find(parent, y);
    
    if(rank[x_rep]>rank[y_rep])  
        parent[y_rep] = x_rep;
    else if(rank[x_rep]<rank[y_rep]) 
        parent[x_rep] = y_rep;
    else
       {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
       }
   }
   
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V);
        for(int i=0;i<V;i++) parent[i] =i;
        vector<int>rank(V,0);
        
        vector<pair<int,pair<int,int>>>edges;   //{wt, {u, v}}
        for(int i= 0;i<V;i++)
        {
           for(auto it : adj[i])
               edges.push_back({it[1], {i,it[0]}});
        }
       
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto it : edges)
        {
            if(find(parent, it.second.first)!=find(parent, it.second.second))
            {
                Union(parent, rank, it.second.first, it.second.second);
                ans += it.first;
            }
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