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

struct Node * Insert(struct Node * root,int key) {
    if(root == NULL) 
        return createNode(key);
    if(key < root->data)
        root->left = Insert(root->left,key);
    else if(key > root->data)
        root->right = Insert(root->right,key);
    else
        printf("Can't inset %d! Key is already present in BST!!\n",key);
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
    
    Insert(p, 2);
    
    //       5
    //      / \
    //     3   6
    //    / \  
    //   1   4
    //    \
    //     2
    
    Insert(p, 7);
    Insert(p, 8);
    
    //       5
    //      / \
    //     3   6
    //    / \   \
    //   1   4   7
    //    \       \
    //     2       8
    
    InOrderTraversal(p);
    return 0;
}