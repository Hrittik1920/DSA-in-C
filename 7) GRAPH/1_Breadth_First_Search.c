#include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue * next;
};

int isEmpty(struct queue * q) {
    if(q==NULL)
        return 1;
    return 0;
}

void enqueue(struct queue ** f,struct queue ** r,int key) {
    struct queue * ptr=(struct queue *)malloc(sizeof(struct queue));
    if(ptr==NULL)
        printf("Queue is full\n");
    else {
        ptr->data=key;
        ptr->next=NULL;
        if(*f==NULL)
            *f=*r=ptr;
        else{
            (*r)->next=ptr;
            *r=ptr;
        }
    }
}

int dequeue(struct queue ** f) {
    int val=-1;
    if(*f==NULL)
        return val;
    else {
        struct queue * ptr=*f;
        *f=(*f)->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

void Traverse(struct queue * f) {
    struct queue * ptr=f;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct queue * f=NULL;
    struct queue * r=NULL;

    //Our Graph
    //      0 --- 1
    //      | \   |
    //      |  \  |
    //      |   \ |
    //      3 --- 2
    //       \   /
    //        \ /
    //         4
    //        / \
    //       /   \  
    //      5     6
    
    int i=0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",i);
    visited[i] = 1;
    enqueue(&f,&r,i);
    while(!isEmpty(f)) {
        int node = dequeue(&f);
        for(int j=0;j<7;j++) {
            if(a[node][j] == 1  &&  visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(&f,&r,j);
            }
        }
    }
    return 0;
}