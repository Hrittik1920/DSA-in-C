#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue * s) {
    if(s->f==s->r)
        return 1;
    return 0;
}

int isFull(struct queue * s) {
    if(s->r==(s->size-1))
        return 1;
    return 0;
}

void enqueue(struct queue * s, int val) {
    if(isFull(s))
        printf("Queue is full\n");
    else {
        s->arr[++s->r]=val;
        printf("Enqueue Element is %d\n",val);
    }
}

int dequeue(struct queue * s) {
    int val=-1;
    if(isEmpty(s))
        printf("Queue is empty\n,");
    else {
        s->f++;
        val=s->arr[s->f];
    }
    return val;
}

void PrintQueueElements(struct queue * s) {
    for(int i=(s->f+1);i<=s->r;i++) {
        printf("%d  ",s->arr[i]);
    }
}


int main()
{
    struct queue * sp = (struct queue *)malloc(sizeof(struct queue));
    sp->size=4;
    sp->f=sp->r=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));

    enqueue(sp, 3);
    enqueue(sp, 4);
    enqueue(sp, 5);
    enqueue(sp, 6);
    
    printf("Dequeue element is %d\n",dequeue(sp));
    printf("Dequeue element is %d\n",dequeue(sp));
    printf("Dequeue element is %d\n",dequeue(sp));
    printf("Dequeue element is %d\n",dequeue(sp));
    
    enqueue(sp, 10);
    enqueue(sp, 11);
    enqueue(sp, 12);
    enqueue(sp, 13);
    
    
    if(isEmpty(sp)) 
        printf("Queue is empty\n");
    if(isFull(sp))
        printf("Queue is Full");
    return 0;
}