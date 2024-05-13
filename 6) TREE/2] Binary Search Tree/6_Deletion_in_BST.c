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

struct Node * inOrderPredecessor(struct Node * root) {
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
}

struct Node * deleteNode(struct Node * root, int val) {
    struct Node * iPre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL  &&  root->right==NULL) {
        free(root);
        return NULL;
    }
    //Search for the delete element
    if(val<root->data)
        root->left=deleteNode(root->left,val);
    else if(val>root->data)
        root->right=deleteNode(root->right,val);
    //when we get the element
    else {
        iPre=inOrderPredecessor(root) ;
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
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