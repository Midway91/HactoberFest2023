#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x){
  switch(x){
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
      return true ;
  }
  return false;
}

string prefix_infix(string p){
  stack <string>s;
  int n= p.size();

  for(int i=n-1; i>=0; i--){
    if(isOperator(p[i])){
      string o1 = s.top();
      s.pop();
      string o2 = s.top();
      s.pop();

      string temp = "("+o1+p[i]+o2+")";

      s.push(temp);
    }
    else{
      s.push(string(1,p[i]));
    }
  }
   return s.top();
}

int main(){
  string s;
  cin >> s;
  cout << prefix_infix(s);
}
