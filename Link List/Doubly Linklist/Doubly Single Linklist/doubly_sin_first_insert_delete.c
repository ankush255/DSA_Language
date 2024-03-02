#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertFirst(int val) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    temp->data = val;
    temp->next = head;
    temp->prev = NULL; // Set prev to NULL for the new node

    if (head != NULL)
    {
        head->prev = temp; // Update previous pointer of the current head node
    }

    head = temp; // Update head pointer to point to the new node
}

void insertEnd(int val) 
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    temp->data = val;
    temp->next = NULL;

    if (head == NULL) 
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}

void deleteFirst() 
{
    if (head == NULL) 
    {
        printf("List is Empty. => Nothing to Delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL; // Set prev of new head to NULL
    }

    free(temp);
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
        while (ptr != NULL) 
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() 
{
    int choice, val;

    printf("\n1. Insert First\n");
    printf("2. Insert Element\n");
    printf("3. Delete First Element\n");
    printf("4. Display\n");
    printf("5. Exit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter First Element: ");
                scanf("%d", &val);
                printf("\n");
                insertFirst(val);
                break;
            case 2:
                printf("Enter Element : ");
                scanf("%d", &val);
                printf("\n");
                insertEnd(val);
                break;
            case 3:
                printf("Deleting First Element...\n\n");
                deleteFirst();
                break;
            case 4:
                printf("Linked List : ");
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
