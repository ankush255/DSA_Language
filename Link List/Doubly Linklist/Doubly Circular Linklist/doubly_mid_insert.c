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
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; 
        head->prev = head; 
    } else {
        struct node *last = head->prev;
        last->next = temp;
        temp->prev = last;
        temp->next = head;
        head->prev = temp;
    }
}

void insertAtMid(int val, int position) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; 
        head->prev = head; 
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
    temp->prev = slow_ptr;
    slow_ptr->next->prev = temp;
    slow_ptr->next = temp;
}

void display() 
{
    struct node *ptr = head;

    if (head == NULL) 
    {
        printf("List is Empty ...\n");
    } else 
        {
            do {
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
                scanf("%d", &val);
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

Enter your choice: 4
Exiting program.

*/