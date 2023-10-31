 bool isSafe(vector<vector<int>> &m,int x,int y,int &n)
{
    if(x>=0 && y>=0 && x<n && y<n && m[x][y]==1){
        return true;
    }
    
    return false;
    
}
bool ratinamaze(vector<string> &ans,int x,int y,int &n,vector<vector<int>> &m){
    
    if(x==n-1 && y==n-1){
        return true;
    }
    
    if(isSafe(m,x,y+1,n)){
        ans.push_back("R");
        cout<<"pushed R at "<<x<<" "<<y<<endl;
        for(auto i:ans){
            cout<<i<<" ";
        }
         cout<<endl;
        if(ratinamaze(ans,x,y+1,n,m)){
            return true;
        }
       
        ans.pop_back();
        cout<<"popped R at "<<x<<" "<<y<<endl;
    }

    if(isSafe(m,x+1,y,n)){
        ans.push_back("D");
        cout<<"pushed D at "<<x<<" "<<y<<endl;
        if(ratinamaze(ans,x+1,y,n,m)){
            return true;
        }
        ans.pop_back();
        cout<<"popped D at "<<x<<" "<<y<<endl;
    }

    
    return false;
    
    
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
      
        vector<string> ans;
        if(ratinamaze(ans,0,0,n,m)){
            cout<<"ye tha ans"<<endl;
             for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
            return ans;
        }
     
        vector<string> ans2;
        ans2.push_back("-1");
        return ans2;
    }
