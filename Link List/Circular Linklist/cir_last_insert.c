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
    if (temp == NULL) 
    {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;

    if (head == NULL) 
    {
        head = temp;
        head->next = head; 
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != head) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head; 
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


/*

1. Insert Last Element
2. Display
3. Exit

Enter your choice: 1
Enter last Element : 100

Enter your choice: 1
Enter last Element : 200

Enter your choice: 1
Enter last Element : 300

Enter your choice: 2
100     200     300

Enter your choice: 1
Enter last Element : 400

Enter your choice: 2
100     200     300     400

Enter your choice: 3
Exiting program...

*/