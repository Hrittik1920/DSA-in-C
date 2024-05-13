#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * createNode(int data) {
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

struct Node * createList() {
    int size=0;
    printf("Enter the size of linked list : ");
    scanf("%d",&size);
    struct Node * s[size];
    for(int i=1;i<=size;i++)
        s[i] = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the Elements:\n");
    for(int i=1;i<=size;i++) {
        scanf("%d",&s[i]->data);
        s[i]->next = s[i+1];
        if(i==size) {
            s[i]->next = NULL;
        }
    }
    return s[1];
}

void traverseList(struct Node * head) {
    struct Node * ptr = head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * findMid(struct Node * head) {
    struct Node * slow = head;
    struct Node * fast = head->next;
    while(fast!=NULL  &&  fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node * merge(struct Node * s1,struct Node * s2) {
    if(s1==NULL)
        return s2;
    if(s2==NULL)
        return s1;
    struct Node * ans = createNode(-1);
    struct Node * ptr = ans;
    while(s1!=NULL  &&  s2!=NULL) {
        if(s1->data < s2->data) {
            ptr->next = s1;
            ptr = s1;
            s1 = s1->next;
        }
        else {
            ptr->next = s2;
            ptr = s2;
            s2 = s2->next;
        }
    }
    while(s1!=NULL) {
        ptr->next = s1;
        ptr = s1;
        s1 = s1->next;
    }
    while(s2!=NULL) {
        ptr->next = s2;
        ptr = s2;
        s2 = s2->next;
    }
    ans = ans->next;
    return ans;
}

struct Node * mergeSort_LL(struct Node * head) {
    // base case
    if(head == NULL  ||  head->next == NULL) {
        return head;
    }

    // Breaking linked list into two halves, after finding mid
    struct Node * mid = findMid(head);

    struct Node * left = head;
    struct Node * right = mid->next;
    mid->next = NULL;

    //recursive call to sort both halves
    left = mergeSort_LL(left);
    right = mergeSort_LL(right);

    // Merging left and right halves
    return merge(left,right);
}

int main()
{
    // struct Node * s1 = createList();
    // struct Node * s2 = createList();
    // traverseList(s1);
    // traverseList(s2);
    // struct Node * result = merge(s1,s2);
    // traverseList(result);

    struct Node * head = createList();
    traverseList(head);
    head = mergeSort_LL(head);
    traverseList(head);

    return 0;
}