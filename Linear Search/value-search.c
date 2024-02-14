#include<stdio.h>
#include<stdlib.h>
#define n 10

int a[n],i;

int value()
{
    for(i=0 ; i<n ; i++)
    {
        a[i]=rand() %50;
        printf("%d\t",a[i]);
    }
}

int linerSearch(int ser)
{
    for(i=0 ; i<n ; i++)
    {
        if(a[i] == ser)
        {
            printf("Array Position is %d\n",a[i]);
        }else{
            printf("\nYour Array is Not Right\n");
        }
    }
}

int main()
{
    value();
    linerSearch(19);

    return  0;
}