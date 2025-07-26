//INFIX TO POSTFIX USING STACK OPERATIONS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char stack[50];
int top = -1;
int size = 50;
char infix[50];
char postfix[50];
char prefix[50];
char reversedInfix[50];
char reversedPrefix[50];
void infixToPrefix(char *infix, char *prefix);
int priority(char symbol);
char push(char item);
int isempty();
char pop();

int main() {
    printf("Enter an infix expression:\n");
    gets(infix);
    
    printf("THE PREFIX EXPRESSION IS:\n");
    infixToPrefix(infix, prefix);
    puts(prefix);
    
    return 0;
}

char push(char item) {
    if (top == size - 1) {
        printf("stack is full\n");
        return 0;
    }
    else {
        top++;
        stack[top] = item;
    }
    return(item);
}

int isempty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

char pop() { 
    char y;
    if (top == -1) {
        printf("stack is empty\n");
        return '\0';
    }
    else {
        y = stack[top];
        top--;
    }
    return(y);
}

void infixToPrefix(char *infix, char *prefix) {
    char symbol;
    char next;
    int p = 0;
    int len = strlen(infix); 

    // Reverse the infix expression
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (infix[i] == '(')
            reversedInfix[j++] = ')';
        else if (infix[i] == ')')
            reversedInfix[j++] = '(';
        else
            reversedInfix[j++] = infix[i];
    }
    reversedInfix[j] = '\0';

    // Convert reversed infix to prefix
    for (int i = 0; i < len; i++) {
        symbol = reversedInfix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                    prefix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (isempty() == 0 && priority(stack[top]) <= priority(symbol))
                    prefix[p++] = pop();
                push(symbol);
                break;
            default:
                prefix[p++] = symbol; // Operand, add directly to prefix
        }
    }
    while (isempty() == 0)
        prefix[p++] = pop();
    prefix[p] = '\0';

    // Reverse the result to get the final prefix expression
    len = strlen(prefix);
    for (int i = 0; i < len; i++)
        prefix[i] = prefix[len - i - 1];
    prefix[len] = '\0';
}
