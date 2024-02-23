#include <stdio.h>
#include <conio.h>
#define n 5

int q[n], front = -1, rear = -1;

void insertFront(int item)
{

    if(front == 0 && rear == n-1 || front == rear +1)
    {
        printf("Overflow");
    }

    if(front == -1)
    {
        front = rear = 0;
    }else if(front == 0)
        {
            front = n-1;
        }else
            {

                front --;
            }
                q[front] = item;

                

}


void insertrear(int data)
{

    if(front == 0 && rear == n-1 || front == rear +1)
    {
        printf("Overflow");
    }
    else
        {
            if (front == -1)
            {
                front = rear = 0;
            }else if(rear == n-1)
            {
                rear =0;
            }else{

                rear++;
            }
                q[rear] = data;

                

        }
}

void deletefront()
{
    if (front == -1 )
    {
        printf("Underflow");
    }
     
        if( front == rear)
        {
            front = rear = -1;
        }else if(front == n - 1)
                {
                    front = 0;
                }else
                    {
                        printf("Delete Front : %d ", q[front]);
                        front++;
                    }
}

void deleterear()
{
    int item;

    if(front == -1 )
    {
        printf("Underflow");
    }

    if(front == rear)
    {
        front = rear = -1;
    }else if(rear == 0)
        {
            rear = n -1;
        }else
            {
                printf("Delete Rear : %d ", q[rear]);
                rear --;
            }
}

void disp()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty");
    }
    else
        {
            printf("Elements :");
            for (i = front; i != rear; i = (i + 1) % n)
            {
                printf("\t%d", q[i]);
            }
            printf("\t%d",q[i]);
        }
}

void exit();

int main()
{
    int choic,item,data;
    printf("\n1. Insert Front");
    printf("\n2. Insert Rear");
    printf("\n3. Delete Front");
    printf("\n4. Delete Rear");
    printf("\n5. Display");
    printf("\n6. Exit");

    while (1)
    {
        printf("\n\nEnter Choice : ");
        scanf("%d", &choic);

        switch (choic)
        {
            case 1:
                printf("Enter Front : ");
                scanf("%d",&item);
                insertFront(item);
                break;

            case 2:
                printf("Enter Rear : ");
                scanf("%d", &data);
                insertrear(data);
                break;

            case 3:
                deletefront();
                break;

            case 4:
                deleterear();
                break;

            case 5:
                disp();
                break;

            case 6:
                exit(0);
                break;


            default:
                printf("Wrong Choice ..");
        }
    }
}

/*

1. Insert
2. Delete
3. Display
4. Exit

Enter Choice : 2
Underflow

Enter Choice : 3
Queue is Empty

Enter Choice : 1
Enter Element : 10


Enter Choice : 1
Enter Element : 20


Enter Choice : 1
Enter Element : 30


Enter Choice : 1
Enter Element : 40


Enter Choice : 3
Elements :
10
20
30
40

Enter Choice : 1
Enter Element : 50


Enter Choice : 1
Overflow

Enter Choice : 3
Elements :
10
20
30
40
50

Enter Choice : 2
Delete : 10

Enter Choice : 3
Elements :
20
30
40
50

Enter Choice : 2
Delete : 20

Enter Choice : 2
Delete : 30

Enter Choice : 3
Elements :
40
50

Enter Choice : 1
Overflow

Enter Choice : 4

*/