// important questions on array
#include <iostream>
#include <stdlib.h>
using namespace std;
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// q1 swap alternate

// int swapalt(int arr[], int n)
// {
//     for (int i = 0; i < n; i += 2)
//     {
//         if (i + 1 < n)
//         {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
// }
// //  q2 find unique number in arr
// int findunique(int arr[], int n)
// {
//     int uni = -1;
//     for (int i = 0; i < n; i++)
//     {
//         bool isUnique = true;
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j && arr[i] == arr[j])
//             {
//                 isUnique = false;
//                 break;
//             }
//         }
//         if (isUnique)
//         {
//             uni = arr[i];
//             break;
//         }
//     }
//     return uni;
// }
//  q3 find duplicates
// approch 1
// int findduplicate(int arr[], int n)
// {
//     int dup = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 dup = dup + 1;
//             }
//         }
//     }
//     return dup;
// }

// approch 2
// int duplicates(int arr[], int n)
// {
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans = ans ^ arr[i];
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 ans = ans ^ j;
//             }
//         }
//         return ans;
//     }
// }
//  mising number in array
// class Solution {
// public:
//     int missingNumber(std::vector<int>& array, int n) {
//         sort(array.begin(), array.end());

//         // Check if 0 is missing
//         if (array[0] != 1) {
//             return 1;
//         }

//         // Check if n is missing
//         if (array[n - 2] != n) {
//             return n;
//         }

//         for (int i = 1; i < n; i++) {
//             if ((i + 1) != array[i]) {
//                 return i + 1;
//                 break;
//             }
//         }

// If no missing number found in the middle, return -1 to indicate an error
//         return -1;
//     }
// };

// q4 intersection of two array
// int intersection(int arrA[], int arrB[], int n, int m)
// {
//     int ans = -1;

//     for (int i = 0; i < n; i++)
//     {
//         int element = arrA[i];
//         for (int j = 0; j < m; j++)
//         {
//             if (element == arrB[j])
//             {
//                 ans=element;
//                 arrB[j]=-6666;
//                 break;
//             }
//         }
//     }

//     return ans; 
// }

// q5 pairsum 
// can store pairs also but using vector
// int pairsum(int arr[],int n,int sum){
//     int noofpair=0;
   
//     for (int i = 0; i <n; i++)
//     {
//        for (int j = i+1; j<n; j++)
//        {
//         if (arr[i]+arr[j]==sum)
//         {
          
//            noofpair=noofpair+1;
//         }
        
//        }
        
//     }
//    return noofpair; 
// }

// q6 sort 0 and 1
int sortzeroone(int arr[],int n){
int i=0;
int j=n-1;
while(i<j){
    while(arr[i]==0){
        i++;
    }
    while(arr[j]==1){
        j--;
    }
swap(arr[i],arr[j]);
i++;
j--;
}

}
int main()
{
    int arr[200] = {1, 0, 1, 0, 0,1,1,0};
 
    sortzeroone(arr,8);
    printarr(arr,8);

    return 0;
}
