#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

int max(int a,int b) {
    return a>b?a:b;
}

int getHeight(struct Node * n) {
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node * createNode(int key) {
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new->data=key;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int getBalanceFactor(struct Node * node) {
    if(node==NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node * rightRotate(struct Node * y) {
    struct Node * x=y->left;
    struct Node * T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}

struct Node * leftRotate(struct Node * x) {
    struct Node * y=x->right;
    struct Node * T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;

    return y;
}

struct Node * insert(struct Node * node,int key) {
    if(node==NULL)
        return(createNode(key));
    if(key < node->data)
        node->left = insert(node->left,key);
    else if(key > node->data)
        node->right = insert(node->right,key);
    
    node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
    int bf=getBalanceFactor(node);

    //Left Left Insertion
    if(bf>1  &&  key < node->left->data)
        return rightRotate(node);
    //Right Right Insertion
    if(bf<-1  &&  key > node->right->data)
        return leftRotate(node);
    //Left Right Insertion
    if(bf>1  &&  key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Right Left Insertion
    if(bf<-1  &&  key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node * inOrderPredecessor(struct Node * root) {
    root = root->left;
    while(root->right!=NULL)
        root = root->right;
    return root;
}

struct Node * delete(struct Node * root,int key) {
    struct Node * ipre;
    if(root == NULL)
        return NULL;
    if(root->left == NULL  &&  root->right == NULL) {
        free(root);
        return NULL;
    }
    if(key < root->data)
        root->left = delete(root->left,key);
    else if(key > root->data)
        root->right = delete(root->right,key);
    else {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = delete(root->left,ipre->data);
    }
    return root;
}

void PreOrderTraversal(struct Node * root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

int main()
{
    struct Node * root=NULL;
    root = insert(root,1);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,5);
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,8);
    root = insert(root,8);
    root = insert(root,10);


    root = delete(root,7);
    root = delete(root,1);

    PreOrderTraversal(root);
    return 0;
}