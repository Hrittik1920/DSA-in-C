#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node * next;
};

int isEmpty(struct Node * top) {
    if(top==NULL)
        return 1;
    else
        return 0;
}

char stackTop(struct Node * top) {
    if(isEmpty(top))
        return 0;
    return top->data;
}


int isFull(struct Node * top) {
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
        return 1;
    return 0;
}

struct Node * push(struct Node * top, char data) {
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
        printf("Stack Overflow!\n");
    else {
        ptr->data=data;
        ptr->next=top;
        top=ptr;
    }
    return top;
}

int pop(struct Node ** top) {
    if(isEmpty(*top))
        return -1;
    else {
        struct Node * ptr=*top;
        *top=(*top)->next;
        int n=ptr->data;
        free(ptr);
        return n;
    }
}

int precedence(char ch) {
    if(ch == '*'  ||  ch == '/')
        return 2;
    else if(ch == '-'  ||  ch == '+')
        return 1;
    return 0;
}

int isOperator(char ch) {
    if(ch == '/'  ||  ch == '*'  ||  ch == '+'  ||  ch == '-')
        return 1;
    return 0;
}

char * infixToPostfix(char * infix) {
    struct Node * top=NULL;
    char * postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0') {
        if(!isOperator(infix[i])) {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else {
            if(precedence(infix[i]) > precedence(stackTop(top))) {
                top = push(top, infix[i]);
                i++;
            }
            else {
                postfix[j]=pop(&top);
                j++;
            }
        }
    }
    while(!isEmpty(top)) {
        postfix[j]=pop(&top);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}


int main()
{
    char * infix = "a-b/c-d*e";
    printf("Postfix is %s\n",infixToPostfix(infix));
}