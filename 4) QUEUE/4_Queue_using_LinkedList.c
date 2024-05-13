#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node * f) {
    if(f==NULL)
        return 1;
    return 0;
}

void enqueue(struct Node ** f, struct Node ** r, int val) {
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
        printf("Queue is full\n");
    else {
        ptr->data=val;
        ptr->next=NULL;
        if(*f==NULL)
            *f=*r=ptr;
        else {
            (*r)->next=ptr;
            *r=ptr;
        }
    }
}

int dequeue(struct Node ** f) {
    int val=-1;
        if(*f==NULL)
    printf("Queue is empty\n");
    else {
        struct Node * ptr=*f;
        *f=(*f)->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void TraverseQueueLinkedList(struct Node * f) {
    struct Node * ptr=f;
    while(ptr!=NULL) {
        printf("%d  ",ptr->data);
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
    
    printf("Dequeue %d\n",dequeue(&f));
    printf("Dequeue %d\n",dequeue(&f));
    printf("Dequeue %d\n",dequeue(&f));
    
    
    TraverseQueueLinkedList(f);
    return 0;
}