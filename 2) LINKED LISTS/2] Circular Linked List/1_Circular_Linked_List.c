#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void TraverseCircularLinklist(struct Node *head){
    struct Node *ptr=head;
    do
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    printf("\n"); 
}

struct Node * ReverseCircularLinklist(struct Node * head,int n) {
    struct Node * p=head;
    while(p->next!=head)
        p=p->next;
    struct Node * prev=p;
    struct Node * next=NULL;
    for(int i=0;i<n;i++) {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}

int main()
{
    int n;
    printf("Enter the size of Your Circular LinkedList:");
    scanf("%d",&n);
    struct Node *s[n];
    for(int i=0;i<n;i++)
    s[i]=(struct Node*)malloc(sizeof(struct Node));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]->data);
        s[i]->next=s[i+1];
        if(i==n-1)
        s[i]->next=s[0];
    }

    TraverseCircularLinklist(s[0]);
    s[0] = ReverseCircularLinklist(s[0],n);
    TraverseCircularLinklist(s[0]);
    return 0;
}