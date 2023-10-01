#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string str = "PendulumKiMaKaBhosda";
    string::iterator it;
    for(it = str.begin() ; it != str.end() ; it++){
        cout<<*it;
    }
    return 0;
}