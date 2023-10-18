#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> v = {2,4,5,3,10};
    v.insert(20);
    v.insert(30);   
    
    // for(int x:v){
    //     cout<<x<<endl;
    // }

    set<int> ::iterator it;
    for(it = v.begin() ; it!=v.end() ; it++){
        cout<<*it<<endl;
    }
     
    return 0;
}