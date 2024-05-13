#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int * ptr;
};

int isEmpty(struct stack * s) {
    if(s->top == -1) 
        return 1;
    else 
        return 0;
}

int isFull(struct stack * s) {
    if(s->top == (s->size-1)) 
        return 1;
    else 
        return 0;
}

void push(struct stack ** s,int data) {
    if(isFull(*s)) {
        printf("Stack overflow!\n");
        return;
    }
    (*s)->ptr[++(*s)->top] = data;
}

int pop(struct stack ** s) {
    if(isEmpty(*s)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    return (*s)->ptr[(*s)->top--];
}

int peek(struct stack ** s) {
    if(isEmpty(*s)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    return (*s)->ptr[(*s)->top];
}

int stackBottom(struct stack ** s) {
    if(isEmpty(*s)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    return (*s)->ptr[0];
}

int main()
{
    struct stack * s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->ptr = (int*)malloc((s->size)*sizeof(int));
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    while(!isEmpty(s)) {
        printf("%d ",peek(&s));
        pop(&s);
    }
    return 0;
}