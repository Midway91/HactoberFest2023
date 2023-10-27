#include<stdio.h>
void main(){
    int i,j,n,bt[20],rt[20],tat[20],wt[20],tot_rem,tot_tat,tot_wt,qt,ct[20],time=0;
    float avg_tat,avg_wt;
    
    printf("Enter the quantum time : ");
    scanf("%d",&qt);
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    
    printf("Enter the burst time in order of their arrival : ");

    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        
        rt[i]=bt[i];
    }
    for(i=0;i<n;i++){
        
        tot_rem+=rt[i];
    }
    i=0;
    while(tot_rem>0){
        if(rt[i]>0){
            if(rt[i]<qt){
                time+=rt[i];
                rt[i]=0;
                
            }
            else{
                time+=qt;
                rt[i]-=qt;
            }
            if(rt[i]==0)
                ct[i]=time;
        }
        i++;
        i%=n;
        tot_rem=0;
        for(j=0;j<n;j++){
            tot_rem+=rt[j];
        }
    }
    
    for(i=0;i<n;i++){
       tat[i]=ct[i];
       wt[i]=tat[i]-bt[i];
    }
    tot_wt=0;
    tot_tat=0;
    printf("\nPID\tBT\tWT\tTAT");
    for(i=0;i<n;i++)
    {
       
        printf("\n%d\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
        
    }
    
    
    for(i=0;i<n;i++)
    {
         tot_tat+=tat[i];
        tot_wt+=wt[i];
    }

}