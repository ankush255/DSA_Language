#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertFirst(int val) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        temp->next = head; // Point to itself since it's the only node
        temp->prev = head; // Point to itself since it's the only node
    } else {
        struct node *last = head->prev;
        temp->next = head;
        temp->prev = last;
        head->prev = temp;
        last->next = temp;
        head = temp;
    }
}

void insertEnd(int val) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        temp->next = head; // Point to itself since it's the only node
        temp->prev = head; // Point to itself since it's the only node
    } else {
        struct node *last = head->prev;
        temp->next = head;
        temp->prev = last;
        head->prev = temp;
        last->next = temp;
    }
}

void display() {
    struct node *ptr = head;

    if (head == NULL) {
        printf("List is Empty ...\n");
    } else {
        do {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}

int main() {
    int choice, val;

    printf("\n1. Insert First\n");
    printf("2. Insert Element\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter First Element : ");
                scanf("%d", &val);
                printf("\n");
                insertFirst(val);
                break;
            case 2:
                printf("Enter Element: ");
                scanf("%d", &val);
                printf("\n");
                insertEnd(val);
                break;
            case 3:
                printf("Linked List: ");
                display();
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while(choice != 4);

    return 0;
}
