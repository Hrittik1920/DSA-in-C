
    q->ptr[q->r] = data;
}

int dequeue(struct cq * q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    q->f = (q->f + 1) % q->size;
    return q->ptr[q->f];
}

int main()
{
    struct cq * q = (struct cq*)malloc(sizeof(struct cq));
    q->size = 5;
    q->f = q->r = -1;
    q->ptr = (int*)malloc(q->size * sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    while(!isEmpty(q)) {
        printf("%d ",dequeue(q));
    }
    printf("\n");
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);
    enqueue(q,11);
    while(!isEmpty(q)) {
        printf("%d ",dequeue(q));
    }
    printf("\n");
    return 0;
}