#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct circularQueue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct circularQueue * q) {
    if(q->f == q->r) {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue * q) {
    if((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

void enqueue(struct circularQueue * q,int val) {
    if(isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    q->r = (q->r+1)%q->size;
    q->arr[q->r] = val;
}

int dequeue(struct circularQueue * q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    q->f = (q->f+1)%q->size;
    return q->arr[q->f];
}

int main()
{
    struct circularQueue * qp=(struct circularQueue*)malloc(sizeof(struct circularQueue));
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

    printf("Dequeue %d\n",dequeue(qp));
    printf("Dequeue %d\n",dequeue(qp));
    printf("Dequeue %d\n",dequeue(qp));
    printf("Dequeue %d\n",dequeue(qp));
    return 0;
}