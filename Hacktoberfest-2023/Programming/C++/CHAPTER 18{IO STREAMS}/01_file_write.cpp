#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    ofstream myFile("My.txt");
    myFile<<"Lets Write A File"<<endl;
    myFile.close();
    return 0;
}