#include<stdio.h>

int main(){

    int time;

    printf("enter the time in 24hrs : ");
    scanf("%d",&time);

    while(1){
       if(time<12){
        printf("Alert:Good Morning");
       } else if(time>=12 && time<=18){
        printf("Alert:Good Afternoon");
       }else if(time>18){
        printf("Alert:Good Evening");
       }break;

    }
    
 return 0; 
}

    
        
      

    



