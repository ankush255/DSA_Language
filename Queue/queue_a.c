#include<stdio.h>
#include<conio.h>
#define n 5

int q[n] , front = -1 , rear = -1;

void insert()
{
    int data;

    if(rear == n-1)
    {
        printf("Overflow");
    }else{
        if(front == -1)
        {
            front = 0;
        }
        printf("Enter Element : ");
        scanf("%d",&data);
        rear++;
        q[rear] = data;

    }
}


void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Underflow");
    }else{
        printf("Delete : %d ",q[front]);
        front++;
    }
}


void disp()
{
    int i;
    if(front == -1)
    {
        printf("Queue is Empty");
    }else{
        printf("Elements :");
        for(i=front ; i<= rear ; i++)
        {
            printf("\n%d",q[i]);
        }
    }
}



int main()
{
    int choic;
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");

    while(1)
    {
         printf("\n\nEnter Choice : ");
         scanf("%d",&choic);

         switch(choic)
         {
                case 1:
                    insert();
                    break;

                case 2:
                    delete();
                    break;

                case 3:
                    disp();
                    break;

                case 4:
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