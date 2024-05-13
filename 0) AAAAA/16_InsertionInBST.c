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

void IterInsert(struct Node * root,int key) {
    struct Node * prev = NULL;
    while(root!=NULL) {
        prev = root;
        if(root->data == key) {
            printf("Can't insert %d! Element is already present in the BST\n",key);
            return;
        }
        if(key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    struct Node * s = createNode(key);
    if(prev == NULL) {
        root = s;
        return;
    }
    if(key < prev->data) {
        prev->left = s;
    } else {
        prev->right = s;
    }
}

struct Node * recInsert(struct Node * root,int key) {
    if(root == NULL) {
        return createNode(key);
    }
    if(key < root->data) {
        root->left = recInsert(root->left,key);
    } else {
        root->right = recInsert(root->right,key);
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
    
    recInsert(p, 2);
    
    //       5
    //      / \
    //     3   6
    //    / \  
    //   1   4
    //    \
    //     2
    
    recInsert(p, 7);
    recInsert(p, 8);
    
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