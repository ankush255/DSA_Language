#include<stdio.h>
#define n 8

int a[n], top = -1;

int display()
{
    if (top < 0)
        printf("Array is Empty");
    else{
            for(int i=0 ; i<=top ; i++)
            {
                printf("%d ",a[i]);
            }
    }
    printf("\n");
}

int insertDelete(int val)
{
    if(top < 0)
    {
        printf("Array is Full\n");
    }else
        {
            a[top] = val;
            top--;
        }
}

int insertEnd(int val)
{
    if(top >= n - 1)
    {
        printf("Array is Full\n");
    }else
        {
            top++;
            a[top] = val;   
        }
}

int main()
{
    insertEnd(10);

    insertEnd(20);
    insertDelete(20);

    insertEnd(30);

    insertEnd(40);
    insertDelete(40);

    insertEnd(50);
    insertEnd(60);
    insertEnd(70);
    insertEnd(80);
    insertEnd(90);
    insertEnd(100);

    display();
}

/*

10  30  50  60  70  80  90  100 

*/