#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data) {
    struct Node * s=(struct Node *)malloc(sizeof(struct Node));
    s->data=data;
    s->left=NULL;
    s->right=NULL;
    return s;
}

int main()
{
    struct Node * p=createNode(3);
    struct Node * p1=createNode(4);
    struct Node * p2=createNode(11);
    
    p->left=p1;
    p->right=p2;
    return 0;
}