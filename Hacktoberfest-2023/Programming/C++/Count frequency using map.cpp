#include <bits/stdc++.h>
using namespace std;

void cFreq(int a[], int n)
{
    unordered_map<int, int> m;
    //count frequencies
    for (int i = 0; i < n; i++)
        m[a[i]]++;

    //traverse through map to print frequencies
    for (auto t : m)
        cout <<"Element: "<< t.first <<" Freq: "<< t.second << endl;
}

int main()
{   int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++){
       cin>>arr[i];
    }  
    cFreq(arr, n);
    return 0;
}
