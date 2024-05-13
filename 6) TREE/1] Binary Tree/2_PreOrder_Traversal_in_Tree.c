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

void PreorderTraversal(struct Node * root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

int main()
{
    struct Node * p=createNode(3);
    struct Node * p1=createNode(4);
    struct Node * p2=createNode(11);
    struct Node * p3=createNode(1);
    struct Node * p4=createNode(6);
    

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    PreorderTraversal(p);
    return 0;
}