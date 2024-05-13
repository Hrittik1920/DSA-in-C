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


// 77777777



void InOrderTraversal(struct Node * root) {
    if(root!=NULL) {
        InOrderTraversal(root->left);
        printf("%d ",root->data);
        InOrderTraversal(root->right);
    }
}

struct Node * Search_Key_Ite(struct Node * root, int key) {
    while(root!=NULL) {
        if(root->data==key)
            return root;
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
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

    int key=2;

    struct Node * n=Search_Key_Ite(p, key);
    if(n!=NULL)
        printf("Found: %d\n",n->data);
    else
        printf("Element is not found\n");
    return 0;
}