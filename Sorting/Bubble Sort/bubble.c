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

    for(j =0 ; j < n ; j++)
    {
        for (i = 0; i < n-j-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                m = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = m;
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