#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;   
};

struct node *head = NULL;

void insertEnd(int val) 
{
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;

    if(head == NULL) 
    {
        head = temp;
        head->next = head; // Point to itself to make it circular
        return;
    }

    struct node *ptr = head;
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

int main() 
{
    int choice, val, position;
    printf("\n1. Enter Element \n");
    printf("2. Insert at Middle \n");
    printf("3. Display \n");
    printf("4. Exit \n\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter Element : ");
                scanf("%d",&val);
                printf("\n");
                insertEnd(val);
                break;

            case 2:
                printf("Enter Middle Element : ");
                scanf("%d", &val);
                printf("Enter Middle Element Position : ");
                scanf("%d", &position);
                insertAtMid(val, position);
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
