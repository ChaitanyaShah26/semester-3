// Program to reverse a Linked List and display it

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the head of the original list
struct Node* list = NULL;

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
void addAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (list == NULL) {
        list = newNode;
    } else {
        struct Node* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete an element from the list
void deleteElement(int data) {
    struct Node* temp = list;
    struct Node* prev = NULL;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        list = temp->next; // Change head
        free(temp);        // Free old head
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the list
void displayList() {
    struct Node* temp = list;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a reversed list from the original list
struct Node* reverseList() {
    struct Node* reversedList = NULL;
    struct Node* temp = list;

    while (temp != NULL) {
        struct Node* newNode = createNode(temp->data);
        newNode->next = reversedList; // Insert at the front of the reversed list
        reversedList = newNode; // Update the head of the reversed list
        temp = temp->next; // Move to the next node in the original list
    }
    
    return reversedList; // Return the new reversed list
}

// Function to display the reversed list
void displayReversedList(struct Node* reversedList) {
    struct Node* temp = reversedList;
    if (temp == NULL) {
        printf("Reversed list is empty.\n");
        return;
    }
    printf("Reversed List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
void main() {
    int choice, data;
    
    clrscr();
    
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Add element at front\n");
        printf("2. Add element at end\n");
        printf("3. Delete element\n");
        printf("4. Display list\n");
        printf("5. Reverse linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at front: ");
                scanf("%d", &data);
                addAtFront(data);
                break;
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;
            case 4:
                displayList();
                break;
            case 5: {
                struct Node* reversedList = reverseList();
                displayReversedList(reversedList);
                break;
            }
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    getch();
}