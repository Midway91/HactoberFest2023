#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int src , int t){
	
	// code here
        unordered_map<int,list<int> > adj;
        for(int i = 0;i<edges.size();i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> vis;
        unordered_map<int,int> parent;
        parent[src] = -1;
        queue<int> q;
        q.push(src);
        
        // BFS
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(auto i:adj[front]) {
                if(!vis[i]) {
                    vis[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }
	
		// shortest path
		vector<int> ans;
		int currNode = t;
		ans.push_back(t);
		
		while(currNode != src) {
			currNode = parent[currNode];
			ans.push_back(currNode);
		}
		reverse(ans.begin(),ans.end());
		return ans;
}
