#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node * next;
};

int isEmpty(struct Node * top) {
    if(top == NULL) {
        return 1;
    }
    return 0;
}

void push(struct Node ** top,char data) {
    struct Node * newChar = (struct Node * )malloc(sizeof(struct Node));
    if(newChar == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newChar->data = data;
    newChar->next = *top;
    *top = newChar;
}

char pop(struct Node ** top) {
    if(isEmpty(*top)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node * ptr = *top;
    int val = ptr->data;
    *top = (*top)->next;
    free(ptr);
    return val;
}

char stackTop(struct Node * top) {
    if(isEmpty(top)) {
        return 0;
    }
    return top->data;
}

int isOperand(char ch) {
    if(ch == '-'|| ch == '*'|| ch == '/'|| ch == '+')
        return 1;
    return 0;
}

int precedence(char ch) {
    if(ch == '-'|| ch == '+')
        return 1;
    else if(ch == '*'|| ch == '/')
        return 2;
    return 0;
}

char * InfixtoPostfix(char * infix) {
    struct Node * top = NULL;
    char * postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i] != '\0') {
        if(!isOperand(infix[i])) {
            postfix[j] = infix[i];
            i++;j++;
        }
        else {
            if(precedence(infix[i]) > precedence(stackTop(top))) {
                push(&top,infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(&top);
                j++;
            }
        }
    }
    while(!isEmpty(top)) {
        postfix[j] = pop(&top);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "a-b/c-d*e";
    printf("Postfix is %s\n",InfixtoPostfix(infix));
    return 0;
}