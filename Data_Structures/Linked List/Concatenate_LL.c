// Program to Concatenate two Linked Lists

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void addAtFront(struct Node** head, int data);
void addAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* node);
void concatenateLists(struct Node** list1, struct Node** list2, struct Node** concatenatedList);
void displayConcatenatedList(struct Node* concatenatedList);

void main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* concatenatedList = NULL;
    int choice, data;
    
    clrscr();
    
    do {
        printf("\nLinked List Operations:\n");
        printf("1. Add Element to List 1 (Front)\n");
        printf("2. Add Element to List 1 (End)\n");
        printf("3. Add Element to List 2 (Front)\n");
        printf("4. Add Element to List 2 (End)\n");
        printf("5. Delete Element from List 1\n");
        printf("6. Delete Element from List 2\n");
        printf("7. Display List 1\n");
        printf("8. Display List 2\n");
        printf("9. Concatenate Lists\n");
        printf("10. Display Concatenated List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to List 1 at front: ");
                scanf("%d", &data);
                addAtFront(&list1, data);
                break;

            case 2:
                printf("Enter data to add to List 1 at end: ");
                scanf("%d", &data);
                addAtEnd(&list1, data);
                break;

            case 3:
                printf("Enter data to add to List 2 at front: ");
                scanf("%d", &data);
                addAtFront(&list2, data);
                break;

            case 4:
                printf("Enter data to add to List 2 at end: ");
                scanf("%d", &data);
                addAtEnd(&list2, data);
                break;

            case 5:
                printf("Enter data to delete from List 1: ");
                scanf("%d", &data);
                deleteNode(&list1, data);
                break;

            case 6:
                printf("Enter data to delete from List 2: ");
                scanf("%d", &data);
                deleteNode(&list2, data);
                break;

            case 7:
                printf("List 1: ");
                displayList(list1);
                break;

            case 8:
                printf("List 2: ");
                displayList(list2);
                break;

            case 9:
                concatenateLists(&list1, &list2, &concatenatedList);
                printf("Lists concatenated successfully.\n");
                break;

            case 10:
                printf("Concatenated List: ");
                displayConcatenatedList(concatenatedList);
                break;

            case 11:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);

    getch();
}

// Function to add a node at the front of the list
void addAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** list1, struct Node** list2, struct Node** concatenatedList) {
    if (*list1 == NULL) {
        *concatenatedList = *list2;
    } else {
        struct Node* last = *list1;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = *list2;
        *concatenatedList = *list1;
    }
    *list2 = NULL; // Clear the second list after concatenation
}

// Function to display the concatenated list
void displayConcatenatedList(struct Node* concatenatedList) {
    if (concatenatedList == NULL) {
        printf("Concatenated list is empty.\n");
        return;
    }
    while (concatenatedList != NULL) {
        printf("%d -> ", concatenatedList->data);
        concatenatedList = concatenatedList->next;
    }
    printf("NULL\n");
}