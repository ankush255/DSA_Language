#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; // New member to store previous node
};

struct node *head = NULL;

void insertEnd(int val) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL; // Set prev to NULL for the new node

    if (head == NULL) 
    {
        head = temp;
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr; // Update the previous node pointer
    }
}

void insertAtLast(int val) 
{
    insertEnd(val);
}

void deleteLast() 
{
    if (head == NULL) 
    {
        printf("List is already empty.\n");
        return;
    } 
    else if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct node *ptr = head;
    while (ptr->next->next != NULL) 
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    printf("Deleted last node.\n");
}

void display() 
{
    struct node *ptr = head;

    if (head == NULL) 
    {
        printf("List is Empty ...");
    } 
    else 
    {
        while (ptr != NULL) 
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main() 
{
    int choice, data;

    printf("1. Insert Last Element\n");
    printf("2. Delete Last Element\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter Element : ");
                scanf("%d", &data);
                printf("\n");
                insertAtLast(data);
                break;

            case 2:
                deleteLast();
                printf("\n");
                break;

            case 3:
                display();
                printf("\n");
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}
