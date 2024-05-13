#include<stdio.h>
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

int match(char a, char b) {
    if(a=='{'  &&  b=='}')
        return 1;
    if(a=='('  &&  b==')')
        return 1;
    if(a=='['  &&  b==']')
        return 1;
    return 0;
}

int Parenthesismatching(char * exp) {
    struct Node * top=NULL;
    char popped_ch;
    for(int i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='('  ||  exp[i]=='['  ||  exp[i]=='{') {
            top=push(top, exp[i]);
        }
        else if(exp[i]==')'  ||  exp[i]==']'  ||  exp[i]=='}') {
            if(isEmpty(top))
                return 0;
            else
                popped_ch = pop(&top);
            if(!match(popped_ch, exp[i]))
                return 0;
        }
    }
    return isEmpty(top);
}

int main()
{
    char * exp = "3*2[-(8+1])";
    if(Parenthesismatching(exp))
        printf("Parenthesis are balanced\n");
    else
        printf("Parenthesis are not balanced\n");
    return 0;
}