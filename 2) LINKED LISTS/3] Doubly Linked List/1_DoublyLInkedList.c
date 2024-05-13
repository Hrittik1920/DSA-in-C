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

void ReverseDoublyLinklist(struct Node * head) {
    struct Node * p = head;
    while(p->next!=NULL)
    p=p->next;
    while(p!=NULL) {
        printf("%d  ",p->data);
        p=p->prev;
    }
    printf("\n");
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
    ReverseDoublyLinklist(s[0]);

    return 0;
}