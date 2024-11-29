/*
    Given a string, remove adjacent duplicate characters. 
    You should use a stack to track the characters and ensure that only one instance of each character is kept. 
    Input String: abbaca
    Output: ca
*/


#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

// Function to remove adjacent duplicates using stack
void removeAdjacentDuplicates(char *str) {
    char stack[MAX];
    int top = -1; // Initialize stack top

    for (int i = 0; str[i] != '\0'; i++) {
        // If stack is not empty and top element is same as current character
        if (top != -1 && stack[top] == str[i]) {
            // Pop the stack (remove the top element)
            top--;
        } else {
            // Push the current character onto the stack
            stack[++top] = str[i];
        }
    }

    // If stack is empty, return an empty string
    if (top == -1) {
        str[0] = '\0';
        return;
    }

    // Construct the result string from the stack
    for (int i = 0; i <= top; i++) {
        str[i] = stack[i];
    }
    str[top + 1] = '\0'; // Null-terminate the result string
}

void main() {
    char str[MAX];
    
    clrscr();
    // Input string using scanf
    printf("Enter a string: ");
    scanf("%s", str); // Read input string

    // Remove adjacent duplicates
    removeAdjacentDuplicates(str);

    // Output the result
    printf("Output: %s\n", str);

    getch();
}