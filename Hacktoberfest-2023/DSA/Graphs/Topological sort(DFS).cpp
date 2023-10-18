PROBLEM:     https://practice.geeksforgeeks.org/problems/topological-sort/1
/*APPROACH 1 :USING STACK
VIDEO:  https://youtu.be/tv8yJLKOZ0g
        https://www.youtube.com/watch?v=Yh6EFazXipA (striver)
	intution ❤❤❤❤❤
	from striver bhaiya's video: since every node will travel it's adjacent first and then at last it will push itself in the stack
	now for  damn sure ....this will insure that for evry u->v....u will come first in topo sort   as first v will be pushed in stack then u will...hence 
	u will be popped out first and hence it will be printed before v.
*/

//DFS IMPLEMENTATION
class Solution
{   private:
   void dfsTopo(int node,vector<int>&vis,stack<int>&st,vector<int> adj[]){
       vis[node]=1;
       for(auto it:adj[node])
       {
        if(!vis[it]){
            dfsTopo(it,vis,st,adj);
        }   
       }
       st.push(node);
   }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V,vector<int> adj[] ) 
	{
	    // code here 
	  vector<int> vis(V,0);
	  stack<int>st;
	  for(int i=0;i<V;i++){
	      if(!vis[i]){
	          dfsTopo(i,vis,st,adj);
	      }
	  }
	  
	 vector<int>topo;
	 while(!st.empty()){
	     topo.push_back(st.top());
	     st.pop();
	 }
	 return topo;
	}
};



