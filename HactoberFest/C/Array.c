#include <stdio.h>
#include <stdlib.h>
# define max 20
/* SORTING*/

int main() {
	int arr[max];
	int n,i,j,search,temp,x;
	int ch,c,insert_val,loc;
	
	do{
		printf("\n1.Create \n2.Display \n3.sort \n4.search \n5.insert \n6.delete");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("\nHow many numbers you want in array :");
				scanf("%d",&n);
	
				printf("\nEnter the %d numbers in array :",n);
				for (i=0;i<n;i++){
					scanf("\t%d",&arr[i]);
				}
			break;
			
			case 2:
				printf("\n-------------The Array is :-------------");
				for(i=0;i<n;i++){
					printf("%5d",arr[i]);
				}
			break;
				
			case 3:
				printf("\n----The sorted Array is :------------\n");
				for(i=0;i<n;i++){
					for(j=i+1;j<n;j++){
						if(arr[i]>arr[j]){
							temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
					}
				}
			break;
				
			case 4:
				printf("\nEnter the number that you want to search :");
				scanf("%d",&search);
				
				for(i=0;i<n;i++){
					if(arr[i]==search){
						x=1;
						break;
					}
				}
				if(x==1){
					printf("Element Found at %d location :",i);
				}
			break;
				
			case 5:
				printf("\nEnter the number that you want to insert and location : ");
				scanf("%d%d",&insert_val,&loc);
				
				for(i=n-1;i>=loc;i--){
					arr[i+1]=arr[i];
				}
				arr[i+1]=insert_val;
				n++;
			break;	
			
			case 6:
				printf("\nEnter the number that you want to delete at location :");	
				scanf("%d",&loc);
				if(loc>=n-1){
					printf("Invalid location");
				}
				else{
					for(i=loc-1;i<n;i++){
						arr[i]=arr[i+1];
					}
				}
				n--;
				for(i=0;i<n;i++){
					printf("%d\n",arr[i]);
				}
				
			break;
			
			default:
				printf("\nWrong choice");		
		}		
		printf("\nIf you want to continue then press 1 otherwise 0: ");
		scanf("%d",&c);
	}while(c==1);
	printf("\n-------Thank you------------");
	return 0;
}
