Algorithm
merge(array, left, middle, right)
Input: The data set array, left, middle and right index

Output: The merged list

Begin
   nLeft := m - left+1
   nRight := right – m
   define arrays leftArr and rightArr of size nLeft and nRight respectively
   for i := 0 to nLeft do
      leftArr[i] := array[left +1]
   done
   for j := 0 to nRight do
      rightArr[j] := array[middle + j +1]
   done
   i := 0, j := 0, k := left
   while i < nLeft AND j < nRight do
      if leftArr[i] <= rightArr[j] then
         array[k] = leftArr[i]
         i := i+1
      else
         array[k] = rightArr[j]
         j := j+1
         k := k+1
   done
   while i < nLeft do
      array[k] := leftArr[i]
      i := i+1
      k := k+1
   done
   while j < nRight do
      array[k] := rightArr[j]
      j := j+1
      k := k+1
   done
End
mergeSort(array, left, right)
Input: An array of data, and lower and upper bound of the array

Output: The sorted Array

Begin
   if lower < right then
      mid := left + (right - left) /2
      mergeSort(array, left, mid)
      mergeSort (array, mid+1, right)
      merge(array, left, mid, right)
End
Example Code
#include<iostream>
using namespace std;
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}
Output
Enter the number of elements: 6
Enter elements:
14 20 78 98 20 45
Array before Sorting: 14 20 78 98 20 45
Array after Sorting: 14 20 20 45 78 98
