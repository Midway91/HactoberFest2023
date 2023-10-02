#include <stdio.h>
#define N 5

int Q[N];
int front = -1;
int end = -1;


void enqueue(int x){
	if(isEmpty()){
		Q[++end] = x;
		++front;
	}
	else if(!isFull()){
		Q[++end] = x;
	}
}

int dequeue(){
	if(!isEmpty()){
		return Q[front++];
	}if(front==end){
		int x = Q[front];
    	front = -1;
    	end = -1;
    	return x;
	}
}

int isFull(){
	if(end == N-1){
		return 1;
	}
	return 0;
}

int isEmpty(){
	if(front==-1 && end ==-1){
		return 1;
	}
	return 0;
}

void display(){
	if(!isEmpty()){
		int i;
		for(i = front ; i <end +1 ; i++){
			printf("%d ", Q[i]);
		}
		printf("\n");
	}
}

int main(){
	enqueue(2);
	enqueue(1);
	enqueue(4);
	enqueue(5);
	enqueue(9);
	enqueue(6);
	display();
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	display();
}
