#include<stdio.h>
#include<stdlib.h>
#define n 10

int arr[n],i,j,m;

int value()
{
    for(i=0 ; i<n ; i++)
    {
        arr[i] = rand() %50;
        printf("%d\t",arr[i]);
    }
}


int bubble_sort()
{

    for(i =0 ; i < n ; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                m = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = m;
            }
        }
    }
    
        printf("\n\n\t\t\t\t=> Answer <=\n\n");

   
}


int main()
{
    value();
    bubble_sort();

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    return 0;
}

/*

41      17      34      0       19      24      28      8       12      14

                                => Answer <=

0       8       12      14      17      19      24      28      34      41

*/