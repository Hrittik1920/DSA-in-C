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

struct Node * InsertAtfirst(struct Node * head) {
    int n;
    printf("Enter the element u want to insert at first:");
    scanf("%d",&n);
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=n;
    ptr->prev=NULL;
    head->prev=ptr;
    ptr->next=head;
    return ptr;
}

struct Node * InsertAtindex(struct Node * head,int r) {
    struct Node * p=head;
    int n,num;
    printf("At which index you want to place the element:");
    scanf("%d",&n);
    if(n<0 || n>r-1) {
        printf("Error!Index doesn't exist.\n");
        return head;
    }
    printf("Enter the element:");
    scanf("%d",&num);
    if(n==0)
    InsertAtfirst(head);
    else {
        struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
        for(int i=0;i<n;i++)
        p=p->next;
        ptr->data=num;
        ptr->prev=p->prev;
        ptr->next=p;
        p->prev->next=ptr;
        p->prev=ptr;
        return head;
    }
}

struct Node * InsertBeforeElement(struct Node * head) {
    struct Node * p=head;
    int n,num;
    printf("Enter the element Before which you want to insert the element:");
    scanf("%d",&n);
    printf("Enter the element:");
    scanf("%d",&num);
    if(p->data==n)
    InsertAtfirst(head);
    else {
        while(p->next!=NULL  &&  p->data!=n) 
        p=p->next;
        if(p->data!=n) {
            printf("Can't insert! because element is not present in the list.\n");
            return head;
        }
        else {
            struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
            ptr->data=num;
            ptr->prev=p->prev;
            ptr->next=p;
            p->prev->next=ptr;
            p->prev=ptr;
            return head;
        }
    }
}

struct Node * InsertAfterElement(struct Node * head) {
    struct Node * p=head;
    int n,num;
    printf("Enter the element after which you want to insert the element:");
    scanf("%d",&n);
    printf("Enter the element:");
    scanf("%d",&num);
    while(p->data!=n) 
    p=p->next;
    if(p->next!=NULL  &&  p->data!=n) {
        printf("Can't insert! because element is not present in the list.\n");
        return head;
    }
    else {
        struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
        ptr->data=num;
        ptr->next=p->next;
        ptr->prev=p;
        p->next=ptr;
        return head;
    }
}

struct Node * InsertAtEnd(struct Node * head) {
    int n;
    struct Node * p=head;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    while(p->next!=NULL)
    p=p->next;
    printf("Enter the element u want to insert at last:");
    scanf("%d",&n);
    ptr->data=n;
    ptr->prev=p;
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

struct Node * AppendDoubleLinklist(struct Node * head) {
    int n;
    struct Node * p = head;
    while(p->next!=NULL)
    p=p->next;
    printf("How many element you want to insert from last:");
    scanf("%d",&n);
    struct Node * s[n];
    for(int i=0;i<n;i++)
    s[i] = (struct Node *)malloc(sizeof(struct Node));
    for(int i=0;i<n;i++)
    scanf("%d",&s[i]->data);
    for(int i=0;i<n;i++) {
        s[i]->next=s[i+1];
        s[i]->prev=s[i-1];
        if(i==0) {
            s[i]->prev=p;
            p->next=s[i];
        }
        if(i==n-1)
        s[i]->next=NULL;
    }
    return head;
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
    s[0] = AppendDoubleLinklist(s[0]);
    TraversDoublyLinklist(s[0]);

    return 0;
}