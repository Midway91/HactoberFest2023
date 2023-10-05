#include<stdio.h>
int main(){
    int n,rev=0;
    printf("Enter a integer: ");
    scanf("%d",&n);
    while(n!=0){
        rev=rev*10+n%10;
        n/=10;
    }
    printf("Reversed number: %d\n",rev);
    return 0;
}
