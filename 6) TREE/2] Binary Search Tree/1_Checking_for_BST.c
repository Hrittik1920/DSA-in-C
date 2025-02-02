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

int isBST(struct Node * root) {
    static struct Node * prev=NULL;
    if(root!=NULL) {
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL  &&  root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}



int main()
{
    struct Node * p=createNode(5);
    struct Node * p1=createNode(3);
    struct Node * p2=createNode(6);
    struct Node * p3=createNode(1);
    struct Node * p4=createNode(4);


    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    InOrderTraversal(p);
    printf("\n");
    printf("%d\n",isBST(p));
    return 0;
}