#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    cout<<"Size = "<<v.size()<<endl;
    for(auto ele: v) cout<<ele<<" ";
    cout<<endl;
}

void printVectorPair(vector<pair<int,int>> &v){
    cout<<"Size = "<<v.size()<<endl;
    for(auto ele: v) cout<<ele.first<<" "<<ele.second<<endl;
}

int main()
{
    //Vector of pairs
    vector<pair<int,int>> a = {{1,2},{3,4},{5,6}};
    printVectorPair(a);

    vector<pair<int,int>> b;
    cout<<"Enter size of Vector Pair = "; int n; cin>>n; cout<<"Enter vector pairs - "<<endl;
    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        // b.push_back(make_pair(x,y));
        b.push_back({x,y});
    }
    printVectorPair(b);


    //Array of Vector
    cout<<"Enter size of array - "; int n1; cin>>n1;
    vector<int> v[n1];
    for(int i=0; i<n1; i++){
        cout<<"Enter size of vector = "; int size; cin>>size; cout<<"Enter elements - ";
        for(int j=0; j<size; j++)
        {
            int temp; cin>>temp; v[i].push_back(temp);
        }cout<<endl;
    }cout<<endl;
    for(int i=0; i<n1; i++){
        printVector(v[i]);
    }


    //Vector of Vector
    vector<vector<int>> p;
    cout<<"Enter number of vectors you want - "; int n2; cin>>n2;
    for(int i=0; i<n2; i++)
    {
        cout<<"Enter size of vector = "; int size; cin>>size; cout<<"Enter elements - ";
        vector<int> temp;
        for(int j=0; j<size; j++)
        {
            int ele; cin>>ele;
            temp.push_back(ele);
        }cout<<endl;
        p.push_back(temp);
    }cout<<endl;

    cout<<"Oh I want to add one more vector to this, i forgot "<<endl; //difference in (array of vector) (size is not dynamic) and (vector of vector) (size is dynamic)
    vector<int> temp = {1,2,3,4,5,6,7};
    p.push_back(temp);
    for(int i=0; i<p.size(); i++)
    {
        printVector(p[i]);
    }

    
}