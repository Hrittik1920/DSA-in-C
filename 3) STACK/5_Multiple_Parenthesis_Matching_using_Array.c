#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

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

int match(char a, char b) {
    if(a == '{'  &&  b == '}')
        return 1;
    if(a == '('  &&  b == ')')
        return 1;
    if(a == '['  &&  b == ']')
        return 1;
    return 0;
}

int parenthesisMatching(char * exp) {
    struct stack * sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    int popped_ch;
    for(int i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='('  ||  exp[i]=='['  ||  exp[i]=='{') {
            push(sp, exp[i]);
        }
        else if(exp[i]==')'  ||  exp[i]==']'  ||  exp[i]=='}') {
            if(isEmpty(sp))
                return 0;
            else
                popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])) 
                return 0;
        }
    }
    return isEmpty(sp);
}


int main()
{
    char * exp = "{7-8[(4+5)(56*8])}";
    //check parenthesis matched or not
    if(parenthesisMatching(exp))
        printf("Parenthesis are balanced\n");
    else
        printf("Parenthesis are not balanced\n");
    return 0;
}