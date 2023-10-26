/*
PROBLEM STATEMENT:
   Given string, for each of its character, find the occurences of the character on right of it.

   Example:
      Input:   "abcdcd"
      Output:  [1,2,2,1,1,0]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> numberOfOccurences(string s){
    unordered_map<char,int> um;
    vector<int> ans(s.size()-1);

    for(int i=s.size()-2; i>=0; i--){
        ans[i] = um[s[i+1]];
        um[s[i]]++;
    }
   
    return ans;
}

int main(){
    string s;
    cout<<"Enter an string";
    cin>>s;
   
    vector<int> ans = numberOfOccurences(s);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}
