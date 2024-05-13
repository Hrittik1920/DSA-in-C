#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data) {
    struct Node * s = (struct Node*)malloc(sizeof(struct Node));
    s->data = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}

void preOrder(struct Node * root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node * root) {
    if(root!=NULL) {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node * root) {
    if(root!=NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct Node * p = createNode(4);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(6);
    struct Node * p3 = createNode(1);
    struct Node * p4 = createNode(3);
    struct Node * p5 = createNode(5);
    struct Node * p6 = createNode(7);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    preOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    postOrder(p);

    return 0;
}