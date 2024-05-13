#include<stdio.h>
#include<stdlib.h>

struct DEqueue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct DEqueue * q) {
    if(q->f==q->r)
        return 1;
    return 0;
}

int isFull(struct DEqueue * q) {
    if(q->r==(q->size-1))
        return 1;
    return 0;
}

void enqueueF(struct DEqueue * q, int val) {
    if(q->f==-1)
        printf("Element can't be insert from ffirst\n");
    else {
        q->arr[q->f]=val;
        q->f--;
    }
}

void enqueueR(struct DEqueue * q, int val) {
    if(isFull(q))
        printf("Queue is full\n");
    else {
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeueF(struct DEqueue * q) {
    int val=-1;
    if(isEmpty(q))
        printf("Queue is empty\n");
    else {
        q->f++;
        val=q->arr[q->f];
    }
    return val;
}

int dequeueR(struct DEqueue * q) {
    int val = -1;
    if(isEmpty(q))
        printf("Queue is empty\n");
    else {
        val=q->arr[q->r];
        q->r--;
    }
    return val;
}

void printQueueElements(struct DEqueue * q) {
    for(int i=(q->f+1);i<=q->r;i++) {
        printf("%d  ",q->arr[i]);
    }
}


int main()
{
    struct DEqueue * qp=(struct DEqueue *)malloc(sizeof(struct DEqueue));
    qp->size=5;
    qp->f=qp->r=-1;
    qp->arr=(int *)malloc(qp->size*sizeof(int));

    enqueueR(qp, 3);
    enqueueR(qp, 4);
    enqueueR(qp, 5);
    enqueueR(qp, 6);
    enqueueR(qp, 7);
    
    dequeueR(qp);
    
    enqueueR(qp, 8);
    
    dequeueF(qp);
    
    enqueueF(qp, 1);
    
    printQueueElements(qp);
    return 0;
}