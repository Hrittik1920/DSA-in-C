#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top) {
    if(top == NULL)
        return 1;
    return 0;
}

int isFull(struct Node * top) {
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL) 
        return 1;
    return 0;
}

void push(struct Node ** top,int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
}

int pop(struct Node ** top) {
    if(isEmpty(*top)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    struct Node * ptr = *top;
    int val = ptr->data;
    (*top) = (*top)->next;
    free(ptr);
    return val;
}

int peek(struct Node ** top) {
    if(isEmpty(*top)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    return (*top)->data;
}

int stackBottom(struct Node ** top) {
    if(isEmpty(*top)) {
        printf("Stack UnderFlow!\n");
        return -1;
    }
    struct Node * ptr = *top;
    while(ptr->next!=NULL) {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node * top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);
    printf("%d\n",stackBottom(&top));
    while(!isEmpty(top)) {
        printf("%d ",peek(&top));
        pop(&top);
    }
    return 0;
}