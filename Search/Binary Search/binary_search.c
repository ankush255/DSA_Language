#include <stdio.h>

int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
int i, min=0, max=9,  n, result;

int value()
{
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
}

int binarySerch(int n, int min, int max)
{

    int mid;
    while (min <= max)
    {
        mid = min + (max - min) / 2;

        if (a[mid] == n)
        {
            return mid;
        }
        else if (a[mid] < n)
            {
                 min = mid + 1;
            }
            else
                {
                    max = mid - 1;
                }
    }
    return -1;
}

int main()
{
    value();

    printf("\n\nEnter value : ");
    scanf("%d", &n);

    result = binarySerch(n, min,max);

    if (result != -1)
    {
        printf("\nYes it is Present [%d].", result);
    }
    else
    {
        printf("\nNot it is Present.");
    }

    return 0;
}

/*

2   4   6   8   10  12  14  16  18  20

Enter value : 10
Yes it is Present [4].


===========================================


2   4   6   8   10  12  14  16  18  20

Enter value : 5
Not it is Present.

*/