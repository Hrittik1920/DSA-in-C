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

void InOrderTraversal(struct Node * root) {
    if(root!=NULL) {
        InOrderTraversal(root->left);
        printf("%d ",root->data);
        InOrderTraversal(root->right);
    }
}

int main()
{
    struct Node * p=createNode(4);
    struct Node * p1=createNode(1);
    struct Node * p2=createNode(6);
    struct Node * p3=createNode(5);
    struct Node * p4=createNode(2);
    

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    InOrderTraversal(p);
    return 0;
}