// problem link: https://www.codechef.com/problems/LUCKYFR
#include <stdio.h>

int main() {
    int i,Num,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
       scanf("%d",&Num);
       int count=0;
       int b=0;
         int n=Num;
       while(n>0){
           b++;
           n=n/10;
           count++;
       }
       int  u=0;
       for(int w=0;w<count;w++){
           int y;
           y=Num%10;
           Num=Num/10;
           if(y==4){
               u++;
           }
       }
       printf("%d\n",u);
    }
	return 0;
}