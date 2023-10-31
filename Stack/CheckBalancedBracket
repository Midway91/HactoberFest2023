#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>

typedef struct pattern{
    char *array;
    int top ;
    int max_size;
}stack;

stack* init_stack(int max_size);
void push(stack* , char x);
void pop(stack* );
void function(stack* , stack* , int max_size);

int main(){
    stack* s1 ;
    stack* s2 ;
    int max_size ;
    printf("Enter size of the string\n");
    scanf("%d",&max_size);
    max_size += 1 ;
    s1 = init_stack(max_size);
    s2 = init_stack(max_size);
    
    scanf("Enter the pattern \n");
    char c;
    for(int i = 0 ; i<max_size ; i++){
        scanf("%c",&c);
        push(s1,c);
        
    }

    function(s1 , s2 , max_size);

    
    return 0 ;
}

stack* init_stack(int max_size){
    stack* s ;
    s = malloc(sizeof(stack));
    if(s== NULL)
        return NULL;
    s->array = malloc((sizeof(char)) * max_size);
    if(s->array == NULL)
        return NULL;
    s->top = -1 ;
    s->max_size = max_size ;
    return s ;
}

void push(stack* s, char x){
    s->top += 1 ;
    s->array[s->top] = x;
}

void pop(stack *s){
    s->top -= 1 ;
}

void function(stack* s1, stack* s2, int max_size){
    for(int i = 0 ; i<max_size ; i++){
        push(s2,s1->array[i]);
        
        if((s2->top)!=0){
            if((s2->array[s2->top] == ']')&&(s2->array[s2->top-1] == '[')){
                pop(s2);
                pop(s2);
            }
            if((s2->array[s2->top] == ')')&&(s2->array[s2->top-1] == '(')){
                pop(s2);
                pop(s2);
            }
            if((s2->array[s2->top] == '}')&&(s2->array[s2->top-1] == '{')){
                pop(s2);
                pop(s2);
           }
        }
    }

    if(s2->top == 0){
        printf("Balanced\n");
    }
    else {
        printf("Not balanced\n");
    }
}
