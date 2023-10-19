#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream readFile;
    readFile.open("My.txt");
    if(readFile.is_open()){
        cout<<"File Is Opened"<<endl;
    }
    string str , str1 , x;
    readFile>>str;
    readFile>>str1;
    readFile>>x;
    cout<<str<<" "<<str1<<" "<<x<<endl;
    if(readFile.eof()){
        cout<<"end of File reached"<<endl;
    }
    return 0;
}