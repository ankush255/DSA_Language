#include<stdio.h>
struct node{
    int data;
    char ch;
    struct node *ptr;
};


int main()
{
    struct node a ,b , c , d;
    a.data = 65;
    a.ch = 'A';
    a.ptr = NULL;

    // printf("Data of A is : %d\n",a.data);     // Data of A is : 65
    // printf("Char of A is : %c\n\n",a.ch);     // Char of A is : A
    

    b.data = 97;
    b.ch = 'a';
    b.ptr = NULL;

    // printf("Data of B is : %d\n",b.data);     // Data of B is : 97
    // printf("Char of B is : %c\n\n",b.ch);     // Char of B is : a



    c.data = 90;
    c.ch = 'Z';
    c.ptr = NULL;

    // printf("Data of C is : %d\n",c.data);     // Data of C is : 90
    // printf("Char of C is : %c\n\n",c.ch);     // Char of C is : Z



    d.data = 122;
    d.ch = 'z';
    d.ptr = NULL;

    // printf("Data of D is : %d\n",d.data);     // Data of D is : 122
    // printf("Char of D is : %c\n\n",d.ch);     // Char of D is : z





    a.ptr = &d;
    printf("Data of D is : %d\n",a.ptr->data);    // Data of D is : 122
    printf("Char of D is : %c\n\n",a.ptr->ch);    // Char of D is : z

    b.ptr = &c;
    printf("Data of C is : %d\n",b.ptr->data);    // Data of C is : 90
    printf("Char of C is : %c\n\n",b.ptr->ch);    // Char of C is : Z

    d.ptr = &b;
    printf("Data of B is : %d\n",d.ptr->data);    // Data of B is : 97
    printf("Char of B is : %c\n\n",d.ptr->ch);    // Char of B is : a

    c.ptr = &a;
    printf("Data of A is : %d\n",c.ptr->data);    // Data of A is : 65
    printf("Char of A is : %c\n",c.ptr->ch);      // Char of A is : A


    return 0;
    
}