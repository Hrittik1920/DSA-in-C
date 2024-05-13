#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top) {
    if(top == NULL) {
        return 1;
    }
    return 0;
}

struct Node * createNode(int data) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node ** top,int data) {
    struct Node * newNode = createNode(data);
    if((*top) == NULL ) {
        (*top) = newNode;
        return;
    }
    newNode->next = (*top);
    (*top) = newNode;
}

int pop(struct Node ** top) {
    if(isEmpty(*top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    struct Node * ptr = *top;
    int val = (*top)->data;
    *top = (*top)->next;
    free(ptr);
    return val;
}

int peek(struct Node * top) {
    if(isEmpty(top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return top->data;
}

int stackTop(struct Node * top) {
    if(isEmpty(top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return top->data;
}

int stackBottom(struct Node * top) {
    if(isEmpty(top)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    struct Node * ptr = top;
    while(ptr->next!=NULL) {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node * top = NULL;
    push(&top,0);
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    
    printf("%d ",stackTop(top));
    printf("%d ",stackBottom(top));
    return 0;
}

// struct stack {
//     int size;
//     int top;
//     int * arr;
// };

// int isEmpty(struct stack * s) {
//     if(s->top == -1) {
//         return 1;
//     }
//     return 0;
// }

// int isFull(struct stack * s) {
//     if(s->top == (s->size-1)) {
//         return 1;
//     }
//     return 0;
// }

// void push(struct stack * s,int data) {
//     if(isFull(s)) {
//         printf("Stack is full!\n");
//         return;
//     }
//     s->top++;
//     s->arr[s->top] = data;
// }

// int pop(struct stack * s) {
//     if(isEmpty(s)) {
//         printf("Stack is empty!\n");
//         return -1;
//     }
//     return s->arr[s->top--];
// }

// int peek(struct stack * s) {
//     if(isEmpty(s)) {
//         printf("Stack is empty!\n");
//         return -1;
//     }
//     return s->arr[s->top];
// }

// int main()
// {
//     // struct stack * s = (struct stack*)malloc(sizeof(struct stack));
//     // s->size = 4;
//     // s->top = -1;
//     // s->arr = (int*)malloc(s->size * sizeof(int));
//     // push(s,2);
//     // push(s,3);
//     // push(s,4);
//     // push(s,5);
//     // while(!isEmpty(s)) {
//     //     printf("%d ",peek(s));
//     //     pop(s);
//     // }
//     return 0;
// }