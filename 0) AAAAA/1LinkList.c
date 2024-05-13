#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * InsertAtFirst(struct Node * head,int data) {
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node * InsertAtLast(struct Node * head,int data) {
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node * ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

struct Node * InsertAfterElement(struct Node * head,int element,int data) {
    struct Node * check = head;
    struct Node * ptr = head;
    struct Node * ptr1 = head->next;
    while(ptr!=NULL  && ptr->data != element) {
        ptr = ptr->next;
        if(ptr1!=NULL) {
            ptr1 = ptr1->next;
        }
    }
    if(ptr==NULL) {
        printf("Element is not present in the list\n");
        return head;
    }
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    ptr->next = newNode;
    newNode->next = ptr1;
    return head;
}

struct Node * InsertBeforeElement(struct Node * head,int element,int data) {
    struct Node * ptr = head;
    struct Node * ptr1 = head->next;
    if(ptr->data == element) {
        return InsertAtFirst(head,data);
    }
    while(ptr1!=NULL  && ptr1->data != element) {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    if(ptr1==NULL) {
        printf("Element is not present in the list\n");
        return head;
    }
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    ptr->next = newNode;
    newNode->next = ptr1;
    return head;
}

struct Node * DeleteAtFirst(struct Node * head) {
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * DeleteAtLast(struct Node * head) {
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void traverseList(struct Node * head) {
    struct Node * ptr = head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * reverseLinklist(struct Node * head) {
    struct Node * temp = NULL;
    struct Node * temp2 = NULL;
    while(head != NULL) {
        temp2 = head->next;
        head->next = temp;
        temp = head;
        head = temp2;
    }
    return temp;
}

int main()
{
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    struct Node * second = (struct Node*)malloc(sizeof(struct Node));
    struct Node * third = (struct Node*)malloc(sizeof(struct Node));
    struct Node * forth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 3;
    second->data = 4;
    third->data = 5;
    forth->data = 6;

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    traverseList(head);
    head = InsertAtFirst(head,2);
    head = InsertAtLast(head,7);
    head = InsertBeforeElement(head,8,0);
    traverseList(head);
    head = DeleteAtFirst(head);
    head = DeleteAtLast(head);
    traverseList(head);
    head = reverseLinklist(head);
    traverseList(head);

    return 0;
}