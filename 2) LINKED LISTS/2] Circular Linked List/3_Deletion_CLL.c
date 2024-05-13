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

struct Node * DeleteAtFirst(struct Node * head) {
    struct Node * p, * q=head;
    while(q->next!=head) 
    q=q->next;
    head=head->next;
    q->next=head;
    free(p);
    return head;
}

struct Node * DeleteAtIndex(struct Node *head,int num) {
    int n;
    struct Node * p=head;
    struct Node * q=head->next;
    printf("At which index u want to delete the element:");
    scanf("%d",&n);
    if(n<0 || n>num-1) {
        printf("Error! Index doesn't exist.\n");
        return head;
    }
    else{
        if(n==0)
        DeleteAtFirst(head);
        else {
            for(int i=0;i<n-1;i++){
                p=p->next;
                q=q->next;
            }
            p->next=q->next;
            free(q);
            return head;
        }
    }
}

struct Node * DeleteAtValue(struct Node * head) {
    int n;
    struct Node * p=head;
    struct Node * q=head->next;
    printf("Enter the element u want to delete:");
    scanf("%d",&n);
    if(head->data==n)
    DeleteAtFirst(head);
    else {
        while(q->data!=n  &&  q->next!=head) {
            p=p->next;
            q=q->next;
        }
        if(q->data!=n) {
            printf("Element is not present in the list.\n");
            return head;
        }
        else {
            p->next=q->next;
            free(q);
            return head;
        }
    }
}

struct Node * DeleteAtEnd(struct Node * head) {
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=head) {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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
    s[0] = DeleteAtEnd(s[0]);
    TraverseCircularLinklist(s[0]);
    return 0;
}