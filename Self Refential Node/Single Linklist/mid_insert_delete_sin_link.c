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

    temp -> data = val;
    temp -> next = NULL;

    if(head == NULL) 
    {
        head = temp;
        return;
    }

    while(ptr-> next != NULL) 
    {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    return;
}

void insertAtMid(int val, int position) 
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;

    if (head == NULL) 
    {
        head = temp;
        temp->next = NULL;
        return;
    }

    struct node *slow_ptr = head;
    struct node *fast_ptr = head->next;

    for (int i = 1; i < position - 1 && fast_ptr != NULL; i++) 
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

    for (int i = 1; i < position - 1 && fast_ptr != NULL; i++) 
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    if (fast_ptr == NULL || fast_ptr->next == NULL) 
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
    } else {
        while(ptr != NULL) 
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
    }
    printf("\n");
}

int main() {
    int choice, data, position , val;
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
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtMid(data, position);
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

/*

1. Enter Element 
2. Insert at Middle 
3. Delete at Middle 
4. Display 
5. Exit 

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

Enter your choice: 4
100     200     300     400     500

Enter your choice: 2
Enter data to insert at middle: 1001
Enter position to insert: 3

Enter your choice: 4
100     200     1001    300     400     500

Enter your choice: 2
Enter data to insert at middle: 2002
Enter position to insert: 5

Enter your choice: 4
100     200     1001    300     2002    400     500

Enter your choice: 3
Enter position to delete: 5
Deleted node at position 5.

Enter your choice: 4
100     200     1001    300     400     500

Enter your choice: 3
Enter position to delete: 4
Deleted node at position 4.

Enter your choice: 4
100     200     1001    400     500

Enter your choice: 5
Exiting program.

*/
