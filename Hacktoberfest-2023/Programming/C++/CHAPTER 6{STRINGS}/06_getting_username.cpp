#include<iostream>
using namespace std;
int main()
{
    string mail = "anushk2201@gmail.com";
    int i = (int)mail.find('@');
    string username = mail.substr(0 , i);
    cout<<"Username is "<<username<<endl;
    return 0;
}