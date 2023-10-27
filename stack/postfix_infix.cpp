#include <bits/stdc++.h>
using namespace std;

int isOperand(char x){
  return (x>='a' && x <='z') || (x>='A' && x<='Z');
}

void postfix_infix(string s){
  string ans;
  stack <string>st;
  int n = s.length();
  for(int i=0; i<n; i++){
    if(isOperand(s[i])){
      string op(1,s[i]);
      st.push(op);
    }
    else{
      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();
      st.push("("+op2+s[i]+op1+")");
    }
  }
  cout << st.top() << endl;
}

int main(){
  string s;
  cin >> s;
  postfix_infix(s);
}
