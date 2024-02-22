#include <stdio.h>
#include <conio.h>
#define n 5

int queue[n];
int front = -1, rear = -1;

void enter(int value) 
{
    if ((rear + 1) % n == front) 
    {
        printf("Array is full\n\n");
        return;
    } else if (front == -1 && rear == -1) 
        {
            front = rear = 0;
        } else 
            {
                rear = (rear + 1) % n;
            }
    queue[rear] = value;
}

int delete() 
{
    int item;
    if (front == -1 && rear == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    } else if (front == rear) 
        {
            item = queue[front];
            front = rear = -1;
        } else 
            {
                item = queue[front];
                front = (front + 1) % n;
            }
    return item;
}

void display() {
    int i;
    if (front == -1 && rear == -1) 
    {
        printf("Queue is empty\n\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i != rear; i = (i + 1) % n) 
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n\n", queue[i]);
}

void exit();

int main() {
    int choice, value;

    printf("\n1. Enter\n2. Delete\n3. Display\n4. Exit\n\n");
    
        
    
    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter Element : ");
                scanf("%d", &value);
                printf("\n");
                enter(value);
                break;
            case 2:
                printf("Delete Element: %d\n\n", delete());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}

/*

1. Enter
2. Delete
3. Display
4. Exit

Enter your choice: 2
Queue is empty
Delete Element: -1

Enter your choice: 3
Queue is empty

Enter your choice: 1
Enter Element : 10

Enter your choice: 1
Enter Element : 20

Enter your choice: 1
Enter Element : 30

Enter your choice: 1
Enter Element : 40

Enter your choice: 1
Enter Element : 50

Enter your choice: 1
Enter Element : 60

Array is full

Enter your choice: 3
Queue elements: 10 20 30 40 50

Enter your choice: 2
Delete Element: 10

Enter your choice: 3
Queue elements: 20 30 40 50

Enter your choice: 2
Delete Element: 20

Enter your choice: 2
Delete Element: 30

Enter your choice: 3
Queue elements: 40 50

Enter your choice: 1
Enter Element : 60

Enter your choice: 1
Enter Element : 70

Enter your choice: 1
Enter Element : 80

Enter your choice: 1
Enter Element : 90

Array is full

Enter your choice: 3
Queue elements: 40 50 60 70 80

Enter your choice: 2
Delete Element: 40

Enter your choice: 3
Queue elements: 50 60 70 80

Enter your choice: 4
*/
