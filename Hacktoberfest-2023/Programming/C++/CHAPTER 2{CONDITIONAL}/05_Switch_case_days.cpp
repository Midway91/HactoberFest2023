#include<iostream>
using namespace std;
int main()
{
    int day;
    cout<<"Enter The Day\n";
    cin>>day;
    switch (day)
    {
    case 1:
        cout<<"Monday";
        break;
    case 2:
        cout<<"Tuesday";
        break;
    case 3:
        cout<<"Wednesday";
        break;
    case 4:
        cout<<"Thursday";
        break;
    default:
        cout<<"Error";
    
    }
    return 0;
}