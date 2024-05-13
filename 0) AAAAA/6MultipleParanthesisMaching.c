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

int match(char a,char b) {
    if(a == '('  &&  b == ')')
        return 1;
    if(a == '['  &&  b == ']')
        return 1;
    if(a == '{'  &&  b == '}')
        return 1;
    return 0;
}

int ParanthesisMatch(char * exp) {
    struct Node * top = NULL;
    char popped_ch;
    for(int i=0;exp[i] != '\0';i++) {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&top,exp[i]);
        }
        if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if(isEmpty(top)) {
                return 0;
            } else {
                popped_ch = pop(&top);
            }
            if(!match(popped_ch,exp[i])) {
                return 0;
            }
        }
    }
    return isEmpty(top);
}

int main()
{
    char * exp = "3*2[-(8+1)]";
    if(ParanthesisMatch(exp))
        printf("Parenthesis are balanced\n");
    else
        printf("Parenthesis are not balanced\n");
    return 0;
}