#include<bits/stdc++.h>
using namespace std;
int main()
{
    //stack - LIFO - push pop top empty
    // queue - FIFO - push pop front back empty

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.empty())
   {
        cout<<s.top()<<" ";
        s.pop(); 
   }
   cout<<endl;

   queue<string> q;
   q.push("abc");
   q.push("ac");
   q.push("bc");
   q.push("aaa");
   while(!q.empty()){
        cout<<q.front()<< " "<<q.back()<<endl;
        q.pop();
   }


}