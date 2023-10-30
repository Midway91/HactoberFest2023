#include<bits/stdc++.h>
using namespace std;

void LIS(int arr[],int n)
{
    vector<vector<int>>ans(n);
    ans[0].push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                if(ans[i].size()<ans[j].size()+1)
                    ans[i]=ans[j];
            }
        }
        ans[i].push_back(arr[i]);
    }
    vector<int> m=ans[0];
    for(vector<int>x : ans)
    {
        if(x.size()>m.size())
            m=x;
    }
    cout<<"LIS : ";
    for(unsigned int i=0;i<m.size();i++)
        cout<<m[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    LIS(arr,n);
}
