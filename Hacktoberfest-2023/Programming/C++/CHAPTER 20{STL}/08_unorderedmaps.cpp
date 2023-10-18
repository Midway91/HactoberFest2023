#include <bits/stdc++.h>
using namespace std;

void printUnorderedMap(unordered_map<int, string> &m)
{
    cout << "Size = " << m.size() << endl;
    for (auto &ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}

void printUnorderedMap(unordered_map<string, int> &m)
{
    cout << "Size = " << m.size() << endl;
    for (auto &ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}

int main()
{
    // same as maps BUT!
    //  1. O(1) time complexity everywhere
    //  2. cannot make maps complex data types, only simple data types like int,float,string,char,etc;
    //  3. these are made from hashmaps, Maps were made of Trees

    unordered_map<int, string> m;
    m[1] = "hare";
    m[4] = "krishna";
    m[2] = "krishna";
    m[-1] = "chant";
    m[3] = "hare";
    m.insert({4, "krishna"});
    m.insert(make_pair(5, "krishna"));
    // long way to print
    unordered_map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl;
    }

    // question (https://youtu.be/okLflHtlCuk?t=337)
    cout << "Enter number of strings - ";
    int n;
    cin >> n;
    cout << "Enter the strings = ";
    unordered_map<string, int> a;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        a[t]++;
    }
    printUnorderedMap(a);


    //MultiMaps - for same keys, different values can exist
}