#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; // New pointer for previous node
};

struct node *head = NULL;

void insertEnd(int val) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        head->prev = head; // Previous pointer also points to itself
        return;
    }

    struct node *last = head->prev; // Get the last node
    last->next = temp;
    temp->prev = last;
    temp->next = head; // Make the new node point back to head
    head->prev = temp; // Update head's previous pointer
}

void insertAtMid(int val, int position) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        head->prev = head; // Previous pointer also points to itself
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position - 1 && current->next != head; i++) 
    {
        current = current->next;
    }

    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
}

void deleteAtMid(int position) 
{
    if (head == NULL) 
    {
        printf("List is Empty. Cannot delete.\n");
        return;
    }

    struct node *current = head;
    for (int i = 1; i < position && current->next != head; i++) 
    {
        current = current->next;
    }

    if (current == head) 
    {
        printf("Cannot delete at position %d. It does not exist.\n", position);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    printf("Deleted node at position %d.\n", position);
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
    }
    printf("\n");
}

int main() 
{
    int choice, val, position;
    printf("\n1. Enter Element \n");
    printf("2. Insert at Middle \n");
    printf("3. Delete at Middle \n");
    printf("4. Display \n");
    printf("5. Exit \n\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter Element : ");
                scanf("%d",&val);
                insertEnd(val);
                printf("\n");
                break;

            case 2:
                printf("Enter data to insert at middle: ");
                scanf("%d", &val);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtMid(val, position);
                printf("\n");
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtMid(position);
                printf("\n");
                break;

            case 4:
                display();
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 5);

    return 0;
}
