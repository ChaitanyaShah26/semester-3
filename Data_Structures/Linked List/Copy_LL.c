// Program to copy a Linked List

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global variables for the linked lists
struct Node* list = NULL; // Original list
struct Node* list2 = NULL; // Copy of the original list

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element at the front of the list
void addAtFront(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list;
    list = newNode;
}

// Function to add an element at the end of the list
void addAtEnd(int data, int listNumber) {
    struct Node* newNode = createNode(data);
    if (listNumber == 1) {
        if (list == NULL) {
            list = newNode;
        } else {
            struct Node* temp = list;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    } else if (listNumber == 2) {
        if (list2 == NULL) {
            list2 = newNode;
        } else {
            struct Node* temp = list2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to delete an element from the list
void deleteElement(int data) {
    struct Node* temp = list;
    struct Node* prev = NULL;

    // If the element to be deleted is the head
    if (temp != NULL && temp->data == data) {
        list = temp->next; // Change head
        free(temp);
        return;
    }

    // Search for the element to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the element was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to copy linked list from list to list2
void copyLinkedList() {
    if (list == NULL) {
        printf("\nOriginal list is empty, cannot copy.\n");
        return;
    }

    // Clear list2 before copying
    list2 = NULL;

    struct Node* temp = list;
    while (temp != NULL) {
        addAtEnd(temp->data, 2); // Add to list2
        temp = temp->next;
    }
}

// Main function to drive the program
void main() {
    int choice, data;
    
    clrscr();
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add element at front\n");
        printf("2. Add element at end\n");
        printf("3. Delete element\n");
        printf("4. Display original list\n");
        printf("5. Copy linked list\n");
        printf("6. Display copied list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to add at front: ");
                scanf("%d", &data);
                addAtFront(data);
                break;
            case 2:
                printf("Enter the data to add at end: ");
                scanf("%d", &data);
                addAtEnd(data, 1);
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;
            case 4:
                displayList(list);
                break;
            case 5:
                copyLinkedList();
                break;
            case 6:
                displayList(list2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    getch();
}