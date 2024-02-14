/*
    logical operator
    
    && => First OPrand Zero Than No Operation Perform On Second Operand
    || => First OPrand One Than No Operation Perform On Second Operand 


    A   B       &&      ||
    0   0       0       0
    0   1       0       1
    1   0       0       1
    1   1       1       1
*/


#include<stdio.h>
int main()
{
    //int a=1 , b=2 , c;

    // c = a && b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = --a && b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = a && ++b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = --a && ++b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // // c = ++a && ++b;
    // printf("A: %d , B: %d , C: %d\n\n",a,b,c);


    // c = a || b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = ++a || b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = ++a || ++b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = ++a || --b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);
    // c = --a || ++b;
    // printf("A: %d , B: %d , C: %d\n",a,b,c);

    int a=2 , b=1 , c=1 , d;

    d= --a && ++b && --c;
    printf("A: %d , B: %d , C: %d , D: %d\n",a,b,c,d);

    return 0;
}