// Merge  Short

#include<stdio.h>
#include<stdlib.h>

void Merge(int a[], int l , int mid , int h )
{
    int b[50];
    int i=l , j=mid+1 , k=l;

    while(i<=mid && j<=h)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= h)
        b[k++] = a[j++];

    for(i=l ; i<=h ; i++)
        a[i] = b[i];
}

int MergeShort(int a[] , int l , int h)
{
    int mid;

    if(l < h)
    {
        mid = (l+h)/2;
        MergeShort(a , l , mid);
        MergeShort(a , mid+1 , h);
        Merge(a , l , mid , h);
    }
}

int main()
{
    int a[15] , n=15 , i;

    for(i=0 ; i<n ; i++)
        a[i] = rand() % 99+1;
        printf("Before Sorting Array is : \n");

    for(i=0 ; i<n ; i++)
        printf("%d\t",a[i]);
        printf("\n");

        MergeShort(a , 0 , n-1);
    printf("\nAfter Sorting Array is : \n");

    for(i=0 ; i<n ; i++)
        printf("%d\t",a[i]);
}

/*

Before Sorting Array is : 
42      54      98      68      63      83      94      55      35      12      63      30      17      97      62

After Sorting Array is : 
12      17      30      35      42      54      55      62      63      63      68      83      94      97      98

*/