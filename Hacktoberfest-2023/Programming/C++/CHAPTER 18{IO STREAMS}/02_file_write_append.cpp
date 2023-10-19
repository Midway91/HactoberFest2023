#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    ofstream myFile("My.txt" , ios::app);
    myFile<<"Mai Phir Se Likhunga"<<endl ;
    myFile.close();
    return 0;
}