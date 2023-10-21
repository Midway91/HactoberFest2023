#include <iostream>
using namespace std;
int calcGCD(int n, int m){

  while (n > 0 && m > 0) {
    if (n > m) n = n % m;
    else m = m % n;
}
  if (n == 0)return m;
  return n;
    
 
}
int main() {
  int n,m;
  cout<<"Enter 1st number"<<" ";
  cin>>n;
  cout<<"Enter 2nd number"<<" ";
  cin>>m;
  cout<<"GCD of the numbers is "<<" ";
  cout<<calcGCD(n,  m);
  return 0;
}