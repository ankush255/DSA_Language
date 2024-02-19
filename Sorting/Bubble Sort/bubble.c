#include<stdio.h>
#include<stdlib.h>
#define n 10

int arr[n],i,s,m;

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

    for(i=0 ; i<n ; i++)
    {
     for (s = 0; s < n; s++)
        {
            if (arr[s] > arr[s + 1])
            {
                m = arr[s + 1];
                arr[s + 1] = arr[s];
                arr[s] = m;
            }
        }
    }
    
        printf("\n\n\t\t\t\tAnswer\n");

   
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