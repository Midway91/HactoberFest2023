#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    cout<<"Size = "<<v.size()<<endl;
    for(auto ele: v) cout<<ele<<" ";
    cout<<endl;
}

int main()
{
    //vector iterator
    vector<int> v = {5,6,7,8};
    printVector(v);
    vector<int> ::iterator it = v.begin();
    cout<<*(it)<<" "<<*(it+1)<<endl;
    for(it =v.begin(); it!=v.end(); it++) //difference between it++ and it+1 is -> it++ goes to next 'itertor' while it+1 goes to next 'memory'
    {
        cout<<*it<<" ";
    }cout<<endl;


    //vector pair iterator
    vector<pair<int,int>> vp = {{1,2},{35,6},{6,7}};
    vector<pair<int,int>> ::iterator i;
    for(i = vp.begin(); i!=vp.end(); i++)
    {
        cout<<(*i).first<<" "<<(*i).second<<endl;
        cout<<i->first<<" "<<i->second<<endl;
    }
}