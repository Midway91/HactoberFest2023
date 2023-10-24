#include <iostream> 
#include<algorithm>
using namespace std;

int main()
{
    int a[]={4,5,3,2,3,5,6,6,5,4,3,5,2,2,1,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    cout<<endl;
    int x=a[0],count=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==x)     count++;
        else
        {
            cout<<x<<"  "<<count<<endl;
            count=1;
            x=a[i];
        }
    }
    cout<<x<<"  "<<count<<endl;
    return 0;
}