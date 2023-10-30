#include <bits/stdc++.h>
using namespace std;

int prec(char c){
  if(c=='^') return 3;
  else if(c=='*' || c=='/') return 2;
  else if(c=='+'|| c=='-') return 1;
  return 0;
}

string infix_postfix(string s){
  string ans ;
  int n = s.length();
  stack <char> st;
  s = '('+s+')';

  for(int i=0; i<n; i++){
    if(isalpha(s[i]) || isdigit(s[i])) ans+= s[i];
    else if(s[i]=='('){
      st.push(s[i]);
    }else if(s[i]==')'){
      while(st.top()!='('){
        ans += st.top();
        st.pop();
      }
      st.pop();
    }
    else{
      while(!st.empty() && prec(s[i]) <= prec(st.top())){
        ans+= st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()){
    ans+= st.top();
    st.pop();
  }
  return s ;
}

void infix_prefix(string s){
  int n = s.length();

  reverse(s.begin(),s.end());

  for(int i=0; i<n; i++){
    if(s[i]=='(') s[i]=')';
    else if(s[i]==')') s[i] = '(';
  }
  string ans = infix_postfix(s);
  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}

int main(){
  string s ;
  cin >> s;
  infix_prefix(s);
}
