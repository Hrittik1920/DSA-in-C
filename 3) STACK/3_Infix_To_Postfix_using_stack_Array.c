#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

char stackTop(struct stack * s) {
    return s->arr[s->top];
}

int isEmpty(struct stack * s) {
    if(s->top==-1)
        return 1;
    return 0;
}

int isFull(struct stack * s) {
    if(s->top==s->size)
        return 1;
    return 0;
}

void push(struct stack * s, char val) {
    if(isFull(s))
        printf("Stack Overflow!\n");
    else {
        s->top++;
        s->arr[s->top]=val;
    }
}

char pop(struct stack * s) {
    if(isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
        return s->arr[s->top--];
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
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    char * postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0') {
        if(!isOperator(infix[i])) {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else {
            if(precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)) {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}


int main()
{
    char * infix = "a-b/c-d*e";
    printf("Postfix Expression is %s",infixToPostfix(infix));
    return 0;
}