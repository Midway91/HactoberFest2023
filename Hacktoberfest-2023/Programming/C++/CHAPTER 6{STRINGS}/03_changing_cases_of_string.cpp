#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string str = "welcome";
    string::iterator it;
    for(it = str.begin() ; it != str.end() ; it++){
        *it = *it - 32;
    }
    cout<<str;
    return 0;
}