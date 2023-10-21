#include <bits/stdc++.h> 
using namespace std; 
  
void towerOfHanoi(int n, char source, destination, 
                  char helper) 
{ 
    if (n == 0) { 
        return; 
    } 
    towerOfHanoi(n - 1, source, helper, destination); 
    cout << "Move disk " << n << " from rod " << from_rod 
         << " to rod " << to_rod << endl; 
    towerOfHanoi(n - 1, helper, destination, source); 
} 
  

int main() 
{ 
    int x = 3; 
  
   
    towerOfHanoi(x, 'A', 'C', 'B'); 
    return 0; 
} 
