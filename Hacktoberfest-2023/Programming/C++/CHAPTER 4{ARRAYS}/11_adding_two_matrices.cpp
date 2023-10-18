#include<iostream>
using namespace std;
int main()
{
    int i , j;
    int arr1[3][3] , arr2[3][3] , sum[3][3];
    cout<<"Enter First Matrices\n";
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter Second Matrices\n";
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"Displaying First Matrices\n";
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            cout<<arr1[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Displaying Second Matrices\n";
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            cout<<arr2[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
        
    }
    cout<<"Displaying Sum Matrices\n";
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            cout<<sum[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}