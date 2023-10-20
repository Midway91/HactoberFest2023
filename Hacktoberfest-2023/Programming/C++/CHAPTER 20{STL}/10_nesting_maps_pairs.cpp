#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<pair<string, string>, vector<int>> m; // wow
    // first name, last name, and marks
    //THE PAIR WILL BE SORTED

    // input
    cout << "Enter how many students : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter first name, last name, how many subjects : ";
        string s1, s2;
        int sub;
        cin >> s1 >> s2 >> sub;
        cout << "Enter subject marks : ";
        for (int j = 0; j < sub; j++)
        {
            int temp;
            cin >> temp;
            m[{s1, s2}].push_back(temp);
        }
    }

    cout << endl
         << endl
         << endl;
    cout<<"The pairs are sorted"<<endl;
    cout << "Okay!! Ho! ho! ho!, Here is what you inputted- " << endl;
    for (auto &student : m)
    {
        auto fullname = student.first;
        auto marks = student.second;
        cout << "First Name : " << fullname.first << endl;
        cout << "Last Name : " << fullname.second << endl;
        cout << "Marks Obtained : ";
        for (auto &mark : marks)
        {
            cout<<mark<<" ";
        }cout<<endl<<endl;;
    }
}