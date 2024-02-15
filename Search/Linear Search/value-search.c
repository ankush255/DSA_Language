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
    printf("\nEnter Search Value : ");
    scanf("%d",&ser);

    for(i=0 ; i<n ; i++)
    {
        if(a[i] == ser)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    value();
    
    int a = linerSearch(0);

    if( a == -1)
    {
        printf("Not in This Array");
    }else{
        printf("Your Array Is [%d]",a);
    }

    return  0;
}

/*

41      17      34      0       19      24      28      8       12      14
Enter The Search Value : 8
Your Array Is [7]



41      17      34      0       19      24      28      8       12      14
Enter The Search Value : 2
Not in This Array

*/