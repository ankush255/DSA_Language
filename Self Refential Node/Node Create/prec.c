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

    // printf("Data of a is : %d\n",a.data);     // Data of a is : 65
    // printf("Char of a is : %c\n\n",a.ch);     // Char of a is : A
    

    b.data = 97;
    b.ch = 'a';
    b.ptr = NULL;

    // printf("Data of b is : %d\n",b.data);     // Data of b is : 97
    // printf("Char of b is : %c\n\n",b.ch);     // Char of b is : a



    c.data = 90;
    c.ch = 'Z';
    c.ptr = NULL;

    // printf("Data of c is : %d\n",c.data);     // Data of c is : 90
    // printf("Char of c is : %c\n\n",c.ch);     // Char of c is : Z



    d.data = 122;
    d.ch = 'z';
    d.ptr = NULL;

    // printf("Data of d is : %d\n",d.data);     // Data of d is : 122
    // printf("Char of d is : %c\n\n",d.ch);     // Char of d is : z





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