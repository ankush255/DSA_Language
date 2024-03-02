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
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) 
    {
        head = temp;
        temp->next = head; 
        temp->prev = head; 
    } else {
        struct node *last = head->prev;
        temp->next = head;
        temp->prev = last;
        head->prev = temp;
        last->next = temp;
        head = temp;
    }
}

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
        temp->next = head; 
        temp->prev = head; 
    } else {
        struct node *last = head->prev;
        temp->next = head;
        temp->prev = last;
        head->prev = temp;
        last->next = temp;
    }
}

void deleteFirst() 
{
    if (head == NULL) 
    {
        printf("List is Empty. Nothing to Delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *last = head->prev;

    if (head->next == head) 
    {
        free(head);
        head = NULL;
    } else {
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
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
            } while (ptr != head);
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
                printf("Enter Element: ");
                scanf("%d", &val);
                printf("\n");
                insertEnd(val);
                break;

            case 3:
                printf("Deleting First Element...\n\n");
                deleteFirst();
                break;

            case 4:
                printf("Linked List: ");
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


/*

1. Insert First
2. Insert Element
3. Delete First Element
4. Display
5. Exit

Enter your choice: 2
Enter Element: 100

Enter your choice: 2
Enter Element: 200

Enter your choice: 2
Enter Element: 300

Enter your choice: 2
Enter Element: 400

Enter your choice: 4
Linked List: 100        200     300     400

Enter your choice: 1
Enter First Element: 800

Enter your choice: 4
Linked List: 800        100     200     300     400

Enter your choice: 1
Enter First Element: 900

Enter your choice: 4
Linked List: 900        800     100     200     300     400

Enter your choice: 3
Deleting First Element...

Enter your choice: 4
Linked List: 800        100     200     300     400

Enter your choice: 3
Deleting First Element...

Enter your choice: 4
Linked List: 100        200     300     400

Enter your choice: 5
Exiting...

*/
