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

struct Node * recursiveSearch(struct Node * root,int key) {
    if(root == NULL) 
        return NULL;
    if(root->data == key) {
        return root;
    }
    if(key < root->data) {
        return recursiveSearch(root->left,key);
    } else {
        return recursiveSearch(root->right,key);
    }
}

struct Node * iterativeSearch(struct Node * root,int key) {
    while(root!=NULL) {
        if(root->data == key) {
            return root;
        }
        else if(root->data > key) {
            root = root->left;
        }
        else
            root = root->right;
    }
    return NULL;
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
    
    struct Node * n=iterativeSearch(p, 5);
    if(n!=NULL)
    printf("Found: %d\n",n->data);
    else
    printf("Element is not found\n");
    return 0;
}