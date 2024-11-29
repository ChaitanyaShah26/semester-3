/*
    Given an expression, check whether the parentheses are balanced or not. 
    i.e. Every opening bracket should have its corresponding closing bracket.
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void push(char ch);
char pop();
int is_Matching(char ch1, char ch2);
int is_Balanced(char *expr);

char stack[MAX];
int tos = -1; // Top of stack

void main() {
    char expression[MAX];
    
    clrscr();
    
    printf("Enter the expression: ");
    scanf("%s", expression); 
    if (is_Balanced(expression))
        printf("\nExpression is Balanced\n");
    else  
        printf("\nExpression is Not Balanced\n");
    
    getch();
}

void push(char ch) { // Push character onto stack
    if (tos == (MAX - 1)) {
        printf("\nStack is Full!\n");
    }
    else
    {
        stack[++tos] = ch; // Increment top and push character
    }
}

char pop() { // Pop character from stack
    if (tos != -1) 
    {
        return stack[tos--]; // Return top character and decrement top
    }
}

int is_Matching(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')') || 
           (ch1 == '{' && ch2 == '}') || 
           (ch1 == '[' && ch2 == ']');
}

int is_Balanced(char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') { // Push opening brackets
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') { // Handle closing brackets
            if (tos == -1 || !is_Matching(pop(), expr[i])) // Check for matching
                return 0; // Not balanced
        }
    }
    return tos == -1; // Return 1 if balanced, 0 otherwise
}