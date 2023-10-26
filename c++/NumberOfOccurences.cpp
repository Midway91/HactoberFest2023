/*
PROBLEM STATEMENT:
   Given string, for each of its character, find the occurences of the character on right of it.

   Example:
      Input:   "abcdcd"
      Output:  [1,2,2,1,1,0]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter an string";
    cin>>s;

    unordered_map<char,int> um;
    vector<int> ans(s.size());

    for(int i=s.size()-1; i>=0; i--){
        ans[i] = um[s[i]];
        um[s[i]]++;
    }

    for(int i=0; i<s.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}