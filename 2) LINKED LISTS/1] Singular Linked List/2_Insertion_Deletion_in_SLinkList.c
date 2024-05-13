#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int s=0;

struct Node {
    int data;
    struct Node * next;
};

struct Node * createNode(int data) {
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    s++;
    return ptr;
}

// ############################################## -- INSERTIONS -- ###########################################################

void InsertAtfirst(struct Node ** head,int data) {
    if(*(head)==NULL) {
        *(head) = createNode(data);
        return;
    }
    struct Node * ptr = createNode(data);
    ptr->data = data;
    ptr->next = *(head);
    *(head) = ptr;
}

void InsertAtlast(struct Node ** head,int data) {
    if(*(head)==NULL) {
        *(head) = createNode(data);
        return;
    }
    struct Node * ptr = *(head);
    struct Node * ptr1 = createNode(data);
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    } 
    ptr->next = ptr1;
}

void InsertAfterElement(struct Node ** head,int data) {
    int element;
    printf("Enter the element after which you want to insert the element : ");
    scanf("%d",&element);
    if(*(head)==NULL) {
        *(head) = createNode(data);
        return;
    }
    struct Node * ptr = createNode(data);
    struct Node * p = *(head);
    // struct Node * q = (*head)->next;
    while(p!=NULL && p->data != element) {
        p = p->next;
        // q = q->next;
    }
    if(p == NULL) {
        printf("Element is not present in the existing linkList!\n");
        s--;
        return;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void InsertBeforeElement(struct Node ** head,int data) {
    int element;
    printf("Enter the element before which you want to insert the element : ");
    scanf("%d",&element);
    if(*(head)==NULL) {
        *(head) = createNode(data);
        return;
    }
    if((*head)->data == element) {
        InsertAtfirst(head,data);
        return;
    }
    struct Node * ptr = createNode(data);
    struct Node * p = (*head)->next;
    struct Node * q = (*head);
    while(p!=NULL && p->data != element) {
        p = p->next;
        q = q->next;
    }
    if(p == NULL) {
        printf("Element is not present in the existing linkList!\n");
        s--;
        return;
    }
    q->next = ptr;
    ptr->next = p;
}

void InsertAtIndex(struct Node ** head,int data) {
    int index;
    printf("Enter the index at which you want to insert the element : ");
    scanf("%d",&index);
    if(*(head)==NULL) {
        *(head) = createNode(data);
        return;
    }
    struct Node * ptr = createNode(data);
    struct Node * p = *(head);
    struct Node * q = (*head)->next;
    if(index<0 || index >= s) {
        printf("Invalid index!\n");
        s--;
        return;
    }
    if(index == 0) {
        InsertAtfirst(head,data);
        return;
    }
    for(int i=0;i<index-1;i++) {
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->next = q;
}

// ############################################## -- DELETION -- ###########################################################

void DeleteAtFirst(struct Node ** head) {
    struct Node * ptr = *head;
    *head = (*head)->next;
    free(ptr);
    s--;
}

void DeleteAtLast(struct Node ** head) {
    struct Node * p = *head;
    struct Node * q = (*head)->next;
    while(q->next!=NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    s--;
}

void DeletetheElement(struct Node ** head) {
    int element;
    printf("Enter the element you want to delete : ");
    scanf("%d",&element);
    if(*(head)==NULL) {
        return;
    }
    if((*head)->data == element) {
        DeleteAtFirst(head);
        return;
    }
    struct Node * p = *(head);
    struct Node * q = (*head)->next;
    while(q!=NULL && q->data != element) {
        p = p->next;
        q = q->next;
    }
    if(q == NULL) {
        printf("Element is not present in the existing linkList!\n");
        return;
    }
    s--;
    p->next = q->next;
    free(p);
}

void DeleteAtIndex(struct Node ** head) {
    int index;
    printf("Enter the index at which you want to delete the element : ");
    scanf("%d",&index);
    if(*(head)==NULL) {
        return;
    }
    struct Node * p = *(head);
    struct Node * q = (*head)->next;
    if(index<0 || index >= s) {
        printf("Invalid index!\n");
        return;
    }
    if(index == 0) {
        DeleteAtFirst(head);
        return;
    }
    for(int i=0;i<index-1;i++) {
        p = p->next;
        q = q->next;
    }
    s--;
    p->next = q->next;
    free(q);
}

int size() {
    return s-1;
}

void printList(struct Node * head) {
    struct Node * ptr = head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node * head = NULL;
    InsertAtfirst(&head,4);
    InsertAtfirst(&head,3);
    InsertAtfirst(&head,2);
    InsertAtfirst(&head,1);
    InsertAtfirst(&head,0);
    printList(head);
    InsertAtIndex(&head,5);
    printList(head);
    printf("%d\n",size());
    DeleteAtFirst(&head);
    DeleteAtLast(&head);
    printList(head);
    printf("%d\n",size());
    DeleteAtIndex(&head);
    printList(head);
    DeletetheElement(&head);
    printList(head);
    printf("%d\n",size());
    return 0;
}