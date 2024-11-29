// Program to split Linked List into halves

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the front
void addAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to split the linked list into two halves
void splitList(struct Node* head, struct Node** list1, struct Node** list2) {
    if (head == NULL || head->next == NULL) {
        printf("Cannot split - List too short\n");
        *list1 = head;
        *list2 = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *list2 = slow->next;
    slow->next = NULL;
}

// Main function to drive the program
void main() {
    struct Node* list = NULL;
    struct Node* list2 = NULL;
    int choice, data;
    
    clrscr();
    
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Add element at front\n");
        printf("2. Add element at end\n");
        printf("3. Delete element\n");
        printf("4. Display list\n");
        printf("5. Split list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at front: ");
                scanf("%d", &data);
                addAtFront(&list, data);
                break;
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addAtEnd(&list, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&list, data);
                break;
            case 4:
                displayList(list);
                break;
            case 5:
                splitList(list, &list, &list2);
                printf("First half: ");
                displayList(list);
                printf("Second half: ");
                displayList(list2);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    getch();
}