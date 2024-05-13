#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void enqueueF(struct Node ** f, struct Node ** r, int val) {
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
        printf("Queue is full\n");
    else {
        ptr->data=val;
        if(*f==NULL) {
            ptr->next=NULL;
            *f=*r=ptr;
        }
        else {
            ptr->next=*f;
            *f=ptr;
        }
    }
}

void enqueueR(struct Node ** f, struct Node ** r, int val) {
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

int dequeueF(struct Node ** f) {
    int val=-1;
    if(*f==NULL)
        printf("Queue is empty\n");
    else {
        struct Node * ptr=*f;
        *f=(*f)->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int dequeueR(struct Node ** f, struct Node **r) {
    int val = -1;
    if(*f==NULL)
        printf("Queue is empty\n");
    else {
        struct Node * p=*f;
        struct Node * q=(*f)->next;
        while(q->next!=NULL) {
            q=q->next;
            p=p->next;
        }
        p->next=NULL;
        *r=p;
        val=q->data;
        free(q);
    }
    return val;
}

void TraverseQueue(struct Node * f) {
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

    enqueueR(&f,&r, 3);
    enqueueR(&f,&r, 4);
    enqueueR(&f,&r, 5);
    enqueueR(&f,&r, 6);
    enqueueR(&f,&r, 7);
    
    
    dequeueF(&f);
    dequeueR(&f, &r);
    
    enqueueF(&f,&r, 10);
    enqueueF(&f,&r, 11);

    TraverseQueue(f);
    return 0;
}