#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;   
};

struct node *head = NULL;

void insertEnd(int val) 
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;

    if(head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        return;
    }

    while(ptr->next != head) 
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head; // Make the last node point back to head to complete the circular linking
}

void insertAtMid(int val, int position) 
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        return;
    }

    struct node *slow_ptr = head;
    struct node *fast_ptr = head->next;

    for (int i = 1; i < position - 1 && fast_ptr != head; i++) 
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    temp->next = slow_ptr->next;
    slow_ptr->next = temp;
}

void deleteAtMid(int position) 
{
    if (head == NULL) 
    {
        printf("List is Empty. Cannot delete.\n");
        return;
    }

    struct node *slow_ptr = head;
    struct node *fast_ptr = head->next;

    for (int i = 1; i < position - 1 && fast_ptr != head; i++) 
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    if (fast_ptr == head || fast_ptr->next == head) 
    {
        printf("Cannot delete at position %d. It does not exist.\n", position);
        return;
    }

    struct node *temp = slow_ptr->next;
    slow_ptr->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

void display() 
{
    struct node *ptr = head;

    if(head == NULL) 
    {
        printf("List is Empty ...");
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

int main() {
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
