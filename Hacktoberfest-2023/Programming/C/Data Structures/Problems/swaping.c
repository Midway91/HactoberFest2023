#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter two numbers here ");
    scanf("%d %d",&a,&b);
    // storing the value of a and b in d and e to use further
    int d=a;
    int e=b;
    c=a;
    a=b;
    b=c;
    printf("Numbers after swapping \n");
    printf("using third variable are %d %d ",a,b);

    d=d+e;
    e=d-e;
    d=d-e;

    printf("\nwithout using third variable %d %d",d,e);
return 0;
}
