#include<iostream>
using namespace std;
int main()
{
    float basic , percentAllow , percentDeduct , netSalary;
    cout<<"Enter Basic Salary\n";
    cin>>basic;
    cout<<"Enter Allowance\n";
    cin>>percentAllow;
    cout<<"Enter Deduction\n";
    cin>>percentDeduct;
    netSalary = basic + basic*percentAllow/100 - basic*percentDeduct/100;
    cout<<netSalary;
    return 0;
}