#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if (isEmpty(queue))
    {
        queue->front=queue->rear=temp;
        return;
    }
        queue->rear->next=temp;
        queue->rear=temp;
}

int dequeue(struct Queue* queue){
    if (isEmpty(queue))
    {
        printf("empty\n");
        return -1;
    }
    struct Node* temp=queue->front;
    int data=temp->data;
    queue->front=queue->front->next;
    free(temp);
    return data;
}

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

struct Stack* createStack() {
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->q1=createQueue();
    stack->q2=createQueue();
    return stack;
}

void push(struct Stack* s1, int data) {
    enqueue(s1->q2, data);
    while(!isEmpty(s1->q1))
    {
        enqueue(s1->q2, dequeue(s1->q1));
    }
    struct Queue* temp=s1->q1;
    s1->q1=s1->q2;
    s1->q2=temp;
}

int pop(struct Stack* s1) {
    if (isEmpty(s1->q1)) {
        printf("stack is empty\n");
        return -1;
    }
    return dequeue(s1->q1);
}

int main(){
    struct Stack *s = createStack();
    printf("\npushed:\n");
    for (int (i) = 1; (i) < 5; ++(i)) {
        push(s,i);
    }
    printf("\ndeleted:\n");
    for (int i = 1; i < 3 ; ++i) {
        printf("%d\n",pop(s));
    }
    printf("\npushed:\n");
    for (int (i) = 6; (i) < 8; ++(i)) {
        push(s,i);
    }
    printf("\ndeleted:\n");
    for (int i = 1; i < 5 ; ++i) {
        printf("%d\n",pop(s));
    }
}
