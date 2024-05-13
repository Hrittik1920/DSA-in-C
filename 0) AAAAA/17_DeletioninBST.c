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

struct Node * inOrderPredessisor(struct Node * root) {
    root = root->left;
    while(root->right!=NULL) {
        root = root->right;
    }
    return root;
}

struct Node * deleteNode(struct Node * root,int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL  &&  root->right == NULL) {
        free(root);
        return NULL;
    }
    struct Node * ipre;
    //Search for the node with value key
    if(key < root->data) {
        root->left = deleteNode(root->left,key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right,key);
    } 
    //Node is found
    else {
        ipre = inOrderPredessisor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left,ipre->data);
    }
    return root;
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

    //       5
    //      / \
    //     3   6
    //    / \  
    //   1   4

    InOrderTraversal(p);
    printf("\n");

    deleteNode(p, 5);
    printf("|Data is %d|\n",p->data);

    InOrderTraversal(p);
    return 0;
}