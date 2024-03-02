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
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL) 
    {
        head = temp;
        return;
    }

    while(ptr->next != NULL) 
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insertAtMid(int val, int position) 
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        return;
    }

    struct node *current = head;

    for (int i = 1; i < position && current != NULL; i++) 
    {
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("Position out of bounds.\n");
        return;
    }

    temp->next = current;
    temp->prev = current->prev;

    if (current->prev != NULL) 
    {
        current->prev->next = temp;
    }
    current->prev = temp;

    if (current == head) 
    {
        head = temp;
    }
}

void display() 
{
    struct node *ptr = head;

    if(head == NULL) 
    {
        printf("List is Empty ...\n");
    } 
    else 
        {
            while(ptr != NULL) 
            {
                printf("%d\t", ptr->data);
                ptr = ptr->next;
            }
        }
    printf("\n");
}

int main() 
{
    int choice, data, position, val;

    printf("\n1. Enter Element\n");
    printf("2. Insert at Middle\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");

    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter Element : ");
                scanf("%d", &val);
                printf("\n");
                insertEnd(val);
                break;

            case 2:
                printf("Enter Middle Element : ");
                scanf("%d", &data);
                printf("Enter Middle Element Position : ");
                scanf("%d", &position);
                insertAtMid(data, position);
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



/*

1. Enter Element
2. Insert at Middle
3. Display
4. Exit

Enter your choice: 1
Enter Element : 100

Enter your choice: 1
Enter Element : 200

Enter your choice: 1
Enter Element : 300

Enter your choice: 1
Enter Element : 400

Enter your choice: 1
Enter Element : 500

Enter your choice: 3
100     200     300     400     500

Enter your choice: 2
Enter Middle Element : 1001
Enter Middle Element Position : 3

Enter your choice: 3
100     200     1001    300     400     500

Enter your choice: 2
Enter Middle Element : 2002
Enter Middle Element Position : 5

Enter your choice: 3
100     200     1001    300     2002    400     500

Enter your choice: 4
Exiting program.

*/