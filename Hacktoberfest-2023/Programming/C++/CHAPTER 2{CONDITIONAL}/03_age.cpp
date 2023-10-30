#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter Your Age\n";
    cin>>age;
    if(age>= 12 && age<=50){
        cout<<"Young";
    }
    else{
        cout<<"Not Young\n";
    }
    return 0;
}