#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node * front) {
    if(front == NULL) 
        return 1;
    return 0;
}

void enqueue(struct Node ** front,struct Node ** rear,int data) {
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(*front)) {
        *front=*rear=newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node ** front,struct Node ** rear) {
    if(isEmpty(*front)) {
        printf("Queue is Empty\n");
        return -1;
    }
    if(*front == *rear) {
        struct Node * ptr = *front;
        int val = ptr->data;
        *front = *rear = NULL;
        free(ptr);
        return val;
    }
    struct Node * ptr = *front;
    int val = ptr->data;
    *front = (*front)->next;
    free(ptr);
    return val;
}

void traverseQueue(struct Node * front) {
    struct Node * ptr = front;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node * f=NULL;
    struct Node * r=NULL;
    
    enqueue(&f, &r, 32);
    enqueue(&f, &r, 23);
    enqueue(&f, &r, 33);
    
    printf("Dequeue %d\n",dequeue(&f,&r));
    printf("Dequeue %d\n",dequeue(&f,&r));
    printf("Dequeue %d\n",dequeue(&f,&r));
    
    
    traverseQueue(f);
    return 0;
}