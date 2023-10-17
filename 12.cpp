// binary search
// binary searcg code 
int bst(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int mid=(start/2) +(end/2);
    while(start<end){

if(key==arr[mid]){
    return mid;
}
else if(key>arr[mid]){
    start=mid+1;
   start++;
}
else if(key<arr[mid]){
    end=mid-1;
    end--;
}
mid=(start/2) +(end/2);
}
return mid;
}
int main(){
    int arr[200]={4,6,9,10,58,60,5};
    bst(arr,7,10);
}