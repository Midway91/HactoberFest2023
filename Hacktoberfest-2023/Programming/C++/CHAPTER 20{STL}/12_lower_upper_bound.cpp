#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ⚠️⚠️data strcture sholud be SORTED ⚠️⚠️

    //determining the LOWER AND UPPER BOUND in a data structure takes O(log(n)) time
    //but it doesn't work efficiently for sets and maps (O(n))
    //As a solution, an alternative syntax with a time complexity of O(log(n)) is used instead.

    cout<<"Argumnets are same as of sorting, third argument is number whose you want to find"<<endl;
    cout<<"Lower bound gives POINTER/ITERATOR of equal or greater element"<<endl;
    cout<<"Upper bound gives POINTER/ITERATOR of greater element"<<endl<<endl;

    int arr[]={4,2,1,5,7};
    sort(arr,arr+6);
    cout<<"Array is = ";
    for(auto ele:arr) cout<<ele<<" ";
    auto p = lower_bound(arr,arr+6,2);
    cout<<endl<<"Lower bound of 2 is "<<*p;
    p = lower_bound(arr,arr+6,3);
    cout<<endl<<"Lower bound of 3 is "<<*p;
    p = upper_bound(arr,arr+6,2);
    cout<<endl<<"Upper bound of 2 is "<<*p;
    p = upper_bound(arr,arr+6, 10);
    cout<<endl<<"Upper bound of 10 is ";
    if(p==arr+6) cout<<"Not found"<<endl;


    vector<int> v = {4,5,5,7,8,25};
    sort(v.begin(), v.end());
    cout<<endl<<endl<<"Vector is = "; for(auto ele:v) cout<<ele<<" "; 
    auto it = lower_bound(v.begin(), v.end(), 5);
    cout<<endl<<"Lower bound of 5 is "<<*it;
    it = lower_bound(v.begin(), v.end(), 6);
    cout<<endl<<"Lower bound of 6 is "<<*it;
    it = upper_bound(v.begin(), v.end(), 7);
    cout<<endl<<"upper bound of 7 is "<<*it;
    it = upper_bound(v.begin(), v.end(), 25);
    cout<<endl<<"upper bound of 25 is ";
    if(it==v.end()) cout<<"not found"<<endl;

    set<int> s = {2,3,5,1,6,9};
    cout<<endl<<"Set =  ";
    for(auto ele: s) cout<<ele<<" "; cout<<endl;
    auto itt = s.lower_bound(3);
    cout<<"Lower bound of 3 is "<<*itt;
    itt = s.lower_bound(4);
    cout<<endl<<"Lower bound of 4 is "<<*itt;
    itt = s.upper_bound(3);
    cout<<endl<<"Upper bound of 3 is "<<*itt;
    itt = s.upper_bound(9);
    cout<<endl<<"Upper bound of 9 is ";
    if(itt==s.end()) cout<<"not found"<<endl;

    map<int,string> m = {{3, "Alice"}, {1, "Bob"}, {7, "Charlie"}, {3, "David"}};
    cout<<endl<<"Map =  "<<endl;
    for(auto ele: m) cout<<ele.first<<" "<<ele.second<<endl;

    auto ittt = m.lower_bound(0);
    cout<<"Lower bound of 0 is "<<ittt->first<<" "<<ittt->second;
    ittt = m.lower_bound(3);
    cout<<endl<<"Lower bound of 3 is "<<ittt->first<<" "<<ittt->second;
    ittt = m.upper_bound(4);
    cout<<endl<<"upper bound of 4 is "<<ittt->first<<" "<<ittt->second;
    ittt = m.lower_bound(10);
    cout<<endl<<"Lower bound of 10 is ";
    if(ittt==m.end()) cout<<"not found"<<endl<<endl;

}