#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string str = "how Many Words";
    int vowels = 0 , consonants = 0 , spaces = 0;   
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ){
            vowels++;
        }
        else if(str[i] == ' '){
            spaces++;
        }
        else{
            consonants++;
        }
    }
    cout<<"Vowels Are "<<vowels<<endl;
    cout<<"Consonants Are "<<consonants<<endl;
    cout<<"Words Are "<<spaces+1<<endl;
    return 0;
}