//  Quick Sort

#include <stdio.h>
#include <stdlib.h>

int n;
void print(int a[])
{
    int i;
    printf("\n");
    for (i = 0; i < n; i++) // enter 2 digit  
        printf("%d  ", a[i]);
}
void Quicksort(int a[], int first, int last)
{
    int i, j, temp, pivot;
    if (first < last)
    {
        print(a);
        pivot = first;
        i = first, j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        Quicksort(a, first, j - 1);
        Quicksort(a, j + 1, last);
    }
}
int main()
{
    int a[25], i;

    printf("How Many Element Enter: ");
    scanf("%d  ", &n);
    
    for(i = 0; i < n; i++)
        a[i] = rand() % 100 + 1;

     print(a);
    Quicksort(a, 0, n - 1);
    printf("\n\nAfter Quick sort: ");
    print(a);
}

/*

How Many Element Enter: 8

42  68  35  1  70  25  79  59  
42  68  35  1  70  25  79  59  
1  25  35  42  70  68  79  59  
1  25  35  42  70  68  79  59  
1  25  35  42  70  68  79  59  
1  25  35  42  59  68  70  79  

After Quick sort: 
1  25  35  42  59  68  70  79 

*/