#include<stdio.h>
#include<stdlib.h>

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
        exit(1);
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
        exit(1);
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

void deleteFirst() {
    if (head == NULL) {
        printf("List is Empty. Nothing to Delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *last = head->prev;

    if (head->next == head) { // Only one node in the list
        free(head);
        head = NULL;
    } else {
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
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
    printf("3. Delete First Element\n");
    printf("4. Display\n");
    printf("5. Exit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter First Element: ");
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
                printf("Deleting First Element...\n\n");
                deleteFirst();
                break;
            case 4:
                printf("Linked List: ");
                display();
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while(choice != 5);

    return 0;
}
