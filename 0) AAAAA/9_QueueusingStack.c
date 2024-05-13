#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack * next;
};

int isEmpty(struct stack * top) {
    if(top == NULL) {
        return 1;
    }
    return 0;
}

struct stack * createNode(int data) {
    struct stack * newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct stack ** top,int data) {
    struct stack * newNode = createNode(data);
    if((*top) == NULL ) {
        (*top) = newNode;
        return;
    }
    newNode->next = (*top);
    (*top) = newNode;
}

int pop(struct stack ** top) {
    if(isEmpty(*top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    struct stack * ptr = *top;
    int val = (*top)->data;
    *top = (*top)->next;
    free(ptr);
    return val;
}

int peek(struct stack * top) {
    if(isEmpty(top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return top->data;
}

static struct stack * s1 = NULL;
static struct stack * s2 = NULL;

void enqueue(int data) {
    while(!isEmpty(s1)) {
        push(&s2,pop(&s1));
    } 
    push(&s1,data);
    while(!isEmpty(s2)) {
        push(&s1,pop(&s2));
    }
}

int QueisEmpty() {
    return isEmpty(s1);
}

int dequeue() {
    if(QueisEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    return pop(&s1);
}

int peekQue() {
    if(QueisEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    return peek(s1);
}

int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    while(!QueisEmpty()) {
        printf("%d ",peekQue());
        dequeue();
    }
    return 0;
}