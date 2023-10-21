#include<iostream>
#include<string.h>
using namespace std;
int main()
{

    string str = "madam";
    string rev = "";
    int len = (int)str.length();
    rev.resize(len);
    for(int i = 0 , j = len - 1 ; i < len ; i++ , j--){
        rev[i] = str[j];
    }
    if(rev.compare(str) == 0){
        cout<<"This String Is A Palindrome"<<endl;
    }
    else{
        cout<<"This String Is Not A Palindrome"<<endl;
    }
    return 0;
}