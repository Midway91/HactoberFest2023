#include<bits/stdc++.h>
using namespace std;

vector<int> downwardDiagonal(int n, vector<vector<int>> a){
		vector<int>ans;
		vector<int>m[2*n];  // 2*n-1 diagonals
		for(int i=0; i<n; i++){
		    for(int j=0; j<n; j++){
		        m[i+j].push_back(a[i][j]);
		    }
		}
		for(auto it:m){
		    for(int i=0; i<it.size(); i++){
		        ans.push_back(it[i]);
		    }
		}
		return ans;
	}

int main(){
    // Diagonal Traversal of a Matrix
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    vector<int>ans = downwardDiagonal(n,a);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}