#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void TraverseLinkedlist(struct Node * head) {
    struct Node * ptr=head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct Node * ReverseLinkedlist(struct Node * head) {
    struct Node * temp=NULL;
    struct Node * temp2=NULL;
    while(head!=NULL) {
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    return temp;
}

int main()
{
    int n;
    printf("Enter the size of linked list:");
    scanf("%d",&n);
    struct Node * s[n];
    for(int i=0;i<n;i++)
        s[i]=(struct Node *)malloc(sizeof(struct Node));
    for(int i=0;i<n;i++) {
        scanf("%d",&s[i]->data);
        s[i]->next=s[i+1];
        if(i==n-1)
            s[i]->next=NULL;
    }
    TraverseLinkedlist(s[0]);
    s[0] = ReverseLinkedlist(s[0]);
    TraverseLinkedlist(s[0]);
    return 0;
}
