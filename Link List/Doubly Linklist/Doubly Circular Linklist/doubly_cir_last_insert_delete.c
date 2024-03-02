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
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != head) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;   
        temp->next = head;  
        head->prev = temp;  
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
    else if (head->next == head) 
    {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct node *ptr = head;
    while (ptr->next->next != head) 
    {
        ptr = ptr->next;
    }
    free(ptr->next); 
    ptr->next = head; 
    head->prev = ptr; 
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


/*

1. Insert Last Element
2. Delete Last Element
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

Enter your choice: 3
100     200     300     400

Enter your choice: 2
Deleted last node.

Enter your choice: 3
100     200     300

Enter your choice: 4
Exiting program.

*/