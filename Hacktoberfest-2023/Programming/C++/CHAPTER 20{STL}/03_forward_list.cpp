#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
    forward_list<int> v = {2,4,5,3,10};
    v.push_front(20);
    v.push_front(30);   
    v.pop_front();
    // for(int x:v){
    //     cout<<x<<endl;
    // }

    forward_list<int> ::iterator it;
    for(it = v.begin() ; it!=v.end() ; it++){
        cout<<*it<<endl;
    }
     
    return 0;
}