#include<stdio.h>
int main()
{
    int a = 14;

    // printf("A: %d\n",a++);                              // A: 14
    // printf("A: %d\n",++a);                              // A: 15

    // printf("A: %d , A: %d\n",a,a++);                    // A: 15 , A: 14
    // printf("A: %d , A: %d\n",a,++a);                    // A: 15 , A: 15
    // printf("A: %d , A: %d\n",a++,a++);                  // A: 15 , A: 14
    // printf("A: %d , A: %d\n",++a,a++);                  // A: 16 , A: 14
    // printf("A: %d , A: %d\n",++a,++a);                  // A: 16 , A: 16

    // printf("A: %d , A: %d , A: %d\n",a,a++,++a);        // A: 16 , A: 15 , A: 16
    // printf("A: %d , A: %d , A: %d\n",a++,a++,++a);      // A: 16 , A: 15 , A: 17
    // printf("A: %d , A: %d , A: %d\n",++a,a++,++a);      // A: 17 , A: 15 , A: 17
    // printf("A: %d , A: %d , A: %d\n",++a,++a,++a);      // A: 17 , A: 17 , A: 17
    printf("A: %d , A: %d , A: %d\n",a++,++a,++a);      // A: 16 , A: 17 , A: 17


    return 0;

}

