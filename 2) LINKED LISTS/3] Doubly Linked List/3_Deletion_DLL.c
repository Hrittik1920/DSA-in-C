#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node *next;
};

void TraversDoublyLinklist(struct Node * head) {
    struct Node * ptr=head;
    while(ptr!=NULL) {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct Node * DeleteAtFirst(struct Node * head) {
    struct Node * ptr = head;
    head->next->prev=NULL;
    head=head->next;
    free(ptr);
    return head;
}

struct Node * DeleteAtLast(struct Node * head) {
    struct Node * p=head;
    while(p->next!=NULL)
    p=p->next;
    p->prev->next=NULL;
    free(p);
    return head;
}

struct Node * DeleteAtIndex(struct Node * head,int r) {
    int n;
    printf("Enter at which index u want to delete the element:");
    scanf("%d",&n);
    if(n<0  ||  n>r-1) {
        printf("Error! Index doesn't exist.");
        return head;
    }
    else if(n==0)
    DeleteAtFirst(head);
    else if(n==r-1)
    DeleteAtLast(head);
    else {
        struct Node * p = head;
        for(int i=0;i<n;i++)
        p=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return head;   
    }
}

struct Node * DeletetheElement(struct Node * head) {
    int n;
    printf("Enter the element you want to delete from the list:");
    scanf("%d",&n);
    struct Node * p = head;
    struct Node * q = head;
    if(p->data==n)
    DeleteAtFirst(head);
    else {
        while(p->next!=NULL  &&  p->data!=n)
        p=p->next;
        while(q->next!=NULL)
        q=q->next;
        if(p->data!=n) {
            printf("Element is not present in the list.\n");
            return head;
        }
        if(p->data==q->data)
        DeleteAtLast(head);
        else {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
            return head;
        }
    }
}


int main()
{
    int n;
    printf("Enter the size of your Double linked list:");
    scanf("%d",&n);
    struct Node * s[n];
    for(int i=0;i<n;i++)
    s[i]=(struct Node *)malloc(sizeof(struct Node));
    for(int i=0;i<n;i++)
    scanf("%d",&s[i]->data);
    for(int i=0;i<n;i++) {
        s[i]->next=s[i+1];
        s[i]->prev=s[i-1];
        if(i==0)
        s[i]->prev=NULL;
        if(i==n-1)
        s[i]->next=NULL;
    }

    TraversDoublyLinklist(s[0]);
    s[0] = DeletetheElement(s[0]);
    TraversDoublyLinklist(s[0]);

    return 0;
}