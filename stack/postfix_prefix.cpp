#include <bits/stdc++.h>
using namespace std;

bool isOperator(char a){
  switch(a){
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      return true;
  }
  return false ;
}

void post_pre(string s){
  stack <string>st;
  string output;
  int n = s.length();

  for(int i=0; i<n; i++){
    char c=s[i];
    if(isOperator(c)){
      string o1= st.top();
      st.pop();
      string o2 = st.top();
      st.pop();

      string temp = s[i] + o2 + o1 ;
      st.push(temp);
    }
    else{
      st.push(string(1,s[i]));
    }
  }
  string ans ="";
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  cout << ans << endl;
}

int main(){
  string s;
  cin >> s ;
  post_pre(s);
}
