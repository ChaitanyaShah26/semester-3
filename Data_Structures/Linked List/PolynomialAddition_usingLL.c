// Program to add two polynomials taken from the user

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Function to insert a term into the polynomial
void insert(struct Node** poly, int coef, int exp) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    // If the polynomial is empty, insert the new term
    if (*poly == NULL) {
        *poly = temp;
        return;
    }

    // Insert the term in the correct position based on the exponent
    struct Node* current = *poly;
    struct Node* prev = NULL;

    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    // If the term with the same exponent exists, add the coefficients
    if (current != NULL && current->exp == exp) {
        current->coef += coef;
        free(temp); // Free the allocated memory for temp
    } else {
        // Insert the new term in the correct position
        if (prev == NULL) {
            temp->next = *poly;
            *poly = temp;
        } else {
            temp->next = current;
            prev->next = temp;
        }
    }
}

// Function to print the polynomial
void print(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    struct Node* current = poly;

    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* add(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to read a polynomial from the user
void readPolynomial(struct Node** poly) {
    int n, coef, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insert(poly, coef, exp);
    }
}

void main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    
    // clrscr();
    
    printf("Enter first polynomial:\n");
    readPolynomial(&poly1);

    printf("Enter second polynomial:\n");
    readPolynomial(&poly2);

    printf("First polynomial: ");
    print(poly1);

    printf("Second polynomial: ");
    print(poly2);

    struct Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);

    getch();
}