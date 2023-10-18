#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int len = 0;
    char str[] = "BaapKoMatSikha";
    for(int i = 0 ; str[i] != '\0' ; i++){
        len++;
    }
    cout<<"Length Of The String Is "<<len;
    return 0;
}