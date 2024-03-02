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
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr; // Set the previous node
    }
}

void insertAtLast(int val) 
{
    insertEnd(val);
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

    printf("1. Insert Last Element\n");
    printf("2. Display\n");
    printf("3. Exit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter last Element : ");
                scanf("%d", &val);
                printf("\n");
                insertAtLast(val);
                break;

            case 2:
                display();
                printf("\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice. Please Enter a Valid Option.\n");
        }
    } while(choice != 3);

    return 0;
}
