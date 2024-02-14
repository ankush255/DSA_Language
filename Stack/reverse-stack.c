#include<stdio.h>
#define n 7

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

int insertFirst(int val)
{
    int l;
    if(top == -1)
        {
            top++;
            a[top]=val;
        }
        else if(top >= n)
            {
                printf("\nArray Is Full\n\n");
            }
            else
                {
                    top++;
                    l = top-1;

                    for(int i = top; i > 0; i--)
                    {
                        a[i]=a[l];
                        l--;
                    }
                a[0]=val;
                }
    
}


int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    insertFirst(50);
    insertFirst(60);
    insertFirst(70);
    insertFirst(80);
    insertFirst(90);
    insertFirst(100);
    

    display();

}

/*

Array Is Full


Array Is Full

80 70 60 50 40 30 20 10

*/