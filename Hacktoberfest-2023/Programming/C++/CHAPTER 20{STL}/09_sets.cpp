#include<bits/stdc++.h>
using namespace std;

void printSet(set<string> &s)
{
    for(auto &ele:s){
        cout<<ele<<" ";
    }cout<<endl;
}

void printSet(unordered_set<string> &s)
{
    for(auto &ele:s){
        cout<<ele<<" ";
    }cout<<endl;
}

void printSet(multiset<string> &s)
{
    for(auto &ele:s){
        cout<<ele<<" ";
    }cout<<endl;
}

int main()
{
    // remove values from key-value pair in map, it will become a set

    set<string> s; // operations O(log(n))
    s.insert("abc");
    s.insert("bcd");
    s.insert("xya");
    s.insert("abc");
    printSet(s);


    auto it = s.find("bcd"); //return iterator, value is not present, it will return s.end()
    if(it != s.end()){
        s.erase(it);
    }
    s.erase("abc"); // you can pass iterator Or values, if value is passed, then all "abc" will be erased
    printSet(s);


    //Unrodered set - all operations O(1) , no complex DS can used here
    unordered_set<string> a;
    a.insert("xya");
    a.insert("bcd");
    a.insert("abc");
    a.insert("abc");
    a.insert("xya");
    a.erase("bcd");
    printSet(a);

    //Multiset - all operationa O(log(n)) - can store multiple keys
    multiset<string> b;
    b.insert("xya");
    b.insert("bcd");
    b.insert("abc");
    b.insert("abc");
    b.insert("xya");
    b.erase("bcd");
    printSet(b);





    
}