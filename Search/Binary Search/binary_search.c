#include<stdio.h>

int a[10]={2,4,6,8,10,12,14,16,18,20};
int i;
int mid,first,last;

int value()
{

    for(i=0 ; i<10 ; i++)
    {
        printf("%d\t",a[i]); 
    }
}

int main()
{
    if(last >= first)
    {
        mid = (last + first)/2;
    }
}