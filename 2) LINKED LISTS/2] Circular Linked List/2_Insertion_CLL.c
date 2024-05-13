#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * InsertAtlast(struct Node * head,int data){
    struct Node *ptr=head;
    struct Node *ptr2=(struct Node*)malloc(sizeof(struct Node));
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr2->data=data;
    ptr->next=ptr2;
    ptr2->next=head;
    return head;
}

void TraverseCircularLinklist(struct Node *head){
    struct Node *ptr=head;
    do
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head); 
    printf("\n");
}

struct Node * InsertAtFirst(struct Node *head,int data){
    struct Node *p=head;
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    while(p->next!=head) 
        p=p->next;
    ptr->data=data;
    ptr->next=head;
    p->next=ptr;
    return ptr;
}

struct Node * AppendNode(struct Node *head){
    struct Node *ptr=head;
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    int n;
    printf("How many element you want to insert:");
    scanf("%d",&n);
    struct Node *s[n];
    for(int i=0;i<n;i++)
        s[i]=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]->data);
        s[i]->next=s[i+1];
        if(i==n-1){
            ptr->next=s[0];
            s[i]->next=head;
        }
    }
    return head;
}

struct Node * InsertAfterElement(struct Node *head) {
    int n,num;
    struct Node *ptr=head;
    struct Node *ptr2=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element after which u want to insert:");
    scanf("%d",&n);
    printf("Enter the element:");
    scanf("%d",&num);
    ptr2->data=num;
    while(ptr->data!=n && ptr->next!=head){
        ptr=ptr->next;
    }
    if(ptr->data!=n)
    printf("Element is not present in the list.\n");
    else{
        ptr2->next=ptr->next;
        ptr->next=ptr2;
    }
    return head;
}

struct Node * InsertBeforeElement(struct Node * head){
    int n,num;
    struct Node * p=head;
    struct Node * q=head->next;
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element before which u want to insert:");
    scanf("%d",&n);
    printf("Enter the element:");
    scanf("%d",&num);
    ptr->data=num;
    if(p->data==n) {
        InsertAtFirst(head,num);
    }
    else {
        while(q->data!=n  &&  q->next!=head) {
            p=p->next;
            q=q->next;
        }
        if(q->data!=n)
        printf("Element is not present in the list.\n");
        else {
            ptr->next=p->next;
            p->next=ptr;
        }
        return head;
    }
}

int main()
{
    int num,q=1;
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
    // while(q)
    // {
    //     printf("****************Welcome*****************\nEnter the number:\n1)Create a circular Linked list\n2)Append(if not then create)\n3)2)Print your List\n");
    // }
    TraverseCircularLinklist(s[0]);
    s[0] = InsertBeforeElement(s[0]);
    TraverseCircularLinklist(s[0]);
    
    return 0;
}