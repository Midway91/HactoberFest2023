//WAP to perform insertion and deletion operation on a 1-d Array
#include<iostream>
using namespace std;
int n;

void insertion(int a[],int num,int pos){
    int i;
    i=n-1;
    while(i>=pos)
   {
     a[i+1]=a[i];
     i--;
   }
   a[pos]=num;
   n=n+1;
}

int deletion(int a[], int pos){
    int i,num;
    num=a[pos];
    i=pos+1;
    while(i<=n-1){
        a[i-1]=a[i];
        i++;
    }
    n=n-1;
    return num;
}
void display(int a[]){
  int i;
  for(i=0;i<n;i++){
  cout<<a[i];
}
}

    int main(){
    int num,pos;
    int a[20]={10,20,30,40,50};
    n=6;
    cout<<"enter the data to be inserted\n";
    cin>>num;
    cout<<"enter the position\n";
    cin>>pos;
    insertion(a,num,pos);
    display(a);
    cout<<"enter the position of deletion\n";
    cin>>pos;
    num=deletion(a,pos);
    cout<<"deleted value\n"<<num<<" ";
    display(a);
    return 0;
}
