#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int size;
    int top;
    int* arr;
};
// Is empty function
int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

//Is Full Function
int isFull(struct Stack *ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}

//Push Funtion
void push(struct Stack *ptr, int m){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack", m);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = m;
    }
}

//Pop Function
void pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack");
    }
    else{
        int val = ptr->arr[ptr->top--];
        printf("%d  ", val);
    }
}

int main(){
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)(calloc(s->size,sizeof(int)));
    printf("Stack has been created successfully\n");

    for(int i=0; i<10; i++){
        push(s, i);
    }
    
    for(int i=0; i<10; i++){
        pop(s);
    }
    // return 0;
}
