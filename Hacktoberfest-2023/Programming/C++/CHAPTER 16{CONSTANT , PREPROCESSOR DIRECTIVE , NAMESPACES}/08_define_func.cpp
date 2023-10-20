#include<iostream>
using namespace std;
#define SQR(x) (x*x) 
#define MSG(x) #x
int main()
{
    cout<<SQR(5)<<endl;
    cout<<MSG(hello);
    return 0;
}