#include<stdio.h>

int a[10]={2,4,6,8,10,12,14,16,18,20};
int i, mid, min, max,x,n, result;


int value()
{
    for(i=0 ; i<10 ; i++)
    {
        printf("%d\t",a[i]); 
    }
}

int binarySerch(int n, int min, int max)
{
    
    if (min <= max )
    {
        int mid;
        mid = min + (max - min) / 2;

        if (mid == n)
        {
            return mid;
        }
        else if (mid < n)
            {
                min = mid +1;
            }
            else 
                {
                     max = mid-1;
                }
    }
    return -1;  
}

int main()
{
    value();

    printf("\n\nEnter value : ");
    scanf("%d", &x);


    result = binarySerch(n, min, max);

    if (result == 1)
    {
        printf("\nYes it is Present [%d].",a);
    }
        else
        {
             printf("\nNot it is Present.");
        }

    return 0;
}