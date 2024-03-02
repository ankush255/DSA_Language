#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
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
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        head->prev = head; // Point to itself to make it doubly circular
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != head) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;   // Set the previous node
        temp->next = head;  // Make the last node point back to head to complete the circular linking
        head->prev = temp;  // Update head's previous pointer to the new last node
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
    else if (head->next == head) // Only one node
    {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct node *ptr = head;
    while (ptr->next->next != head) // Traverse until the second last node
    {
        ptr = ptr->next;
    }
    free(ptr->next); // Free the last node
    ptr->next = head; // Update the next pointer of the second last node to point to head
    head->prev = ptr; // Update head's previous pointer to the new last node
    printf("Deleted last node.\n");
}

void display() 
{
    struct node *ptr = head;

    if (head == NULL) 
    {
        printf("List is Empty ...\n");
    } 
    else 
    {
        do 
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } while(ptr != head);
        printf("\n");
    }
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

        switch(choice) {
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
