#include <stdio.h>
#define length 5

int stack[length];
int tos =-1;

void push(int x){
	if(!isFull()){
		stack[++tos] = x;
	}
}

int pop(){
	if(!isEmpty())
		return stack[tos--];
}

int isFull(){
	if(tos >= length-1)
		return 1;
	return 0;
}

int isEmpty(){
	if(tos == -1)
		return 1;
	return 0;
}

void peek(){
	if(!isEmpty())
		printf("%d ", stack[tos]);
}

void display(){
	int i;
	
	for(i=tos; i >=0; i--){
		printf("%d ", stack[i]);	
	}
	
	printf("\n");
}

int main(){
	push(1);
	push(2);
	push(3);
	push(9);	
	display();
	pop();
	display();
	pop();
	display();
}
