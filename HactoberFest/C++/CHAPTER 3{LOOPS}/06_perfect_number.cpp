#include<iostream>
using namespace std;
int main()
{
    int n , i , sum = 0;
    cout<<"Enter The Number\n";
    cin>>n;
    
    for(i=1 ; i<=n ;i++){
        if(n%i == 0){
            sum = sum+i;
        }
        
    }
    cout<<sum<<endl;
if(sum == 2*n){
    cout<<n<<" is a Perfect Number\n";
}
else{
    cout<<n<<" is not a perfect number\n";
}
    return 0;
}