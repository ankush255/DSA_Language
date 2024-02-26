// Self Fefential Node

#include<stdio.h>
struct node{
    int data;
    char ch;
    struct node *ptr;
};


int main()
{
    struct node a ,b;
    a.data = 65;
    a.ch = 'A';
    a.ptr = NULL;

    // printf("Data of a is : %d\n",a.data);   // Data of a is : 65
    // printf("Char of a is : %c\n",a.ch);     // Char of a is : A
    

    b.data = 97;
    b.ch = 'a';
    b.ptr = NULL;

    // printf("Data of b is : %d\n",b.data);   // Data of b is : 97
    // printf("Char of b is : %c\n",b.ch);     // Char of b is : a



    a.ptr = &b;
    printf("Data of b is : %d\n",a.ptr->data);  // Data of b is : 97
    printf("Char of b is : %c\n",a.ptr->ch);    // Char of b is : a

    b.ptr = &a;
    printf("Data of a is : %d\n",b.ptr->data);  // Data of a is : 65
    printf("Char of a is : %c\n",b.ptr->ch);    // Char of a is : A

    return 0;
    
}