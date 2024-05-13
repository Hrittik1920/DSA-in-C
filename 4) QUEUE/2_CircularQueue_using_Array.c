#include<stdio.h>
#include<stdlib.h>

struct circularqueue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct circularqueue * q) {
    if(q->f==q->r)
        return 1;
    return 0;
}

int isFull(struct circularqueue * q) {
    if((q->r+1)%q->size==q->f)
        return 1;
    return 0;
}

void enqueue(struct circularqueue * q, int val) {
    if(isFull(q))
        printf("Queue is full\n");
    else {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Enqueue %d\n",val);
    }
}

int dequeue(struct circularqueue * q) {
    int val=-1;
    if(isEmpty(q))
        printf("Queue is empty\n");
    else {
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
    }
    return val;
}


int main()
{
    struct circularqueue * qp=(struct circularqueue*)malloc(sizeof(struct circularqueue));
    qp->size=4;
    qp->f=qp->r=0;
    qp->arr=(int *)malloc(qp->size*sizeof(int));
    
    enqueue(qp, 3);
    enqueue(qp, 4);
    enqueue(qp, 5);
    
    printf("Dequeue %d\n",dequeue(qp));
    printf("Dequeue %d\n",dequeue(qp));
    printf("Dequeue %d\n",dequeue(qp));
    
    enqueue(qp, 10);
    enqueue(qp, 11);
    enqueue(qp, 12);
  
    
    return 0;
}