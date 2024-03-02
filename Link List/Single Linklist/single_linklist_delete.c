#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;   
};

struct node *head = NULL;

void insertEnd(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp -> data = val;
    temp -> next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    while(ptr-> next != NULL)
    {
        ptr = ptr -> next;
    }
        ptr -> next = temp;
        return;
}

void deleteEnd(){
    struct node *ptr = head;
    struct node *p;

    if(head == NULL){
        printf("List is Already Empty...");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }

    while(ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return;
}

void display()
{
    struct node *ptr = head;

    if(head == NULL)
    {
        printf("List is Empty ...");
    }else{
        while(ptr != NULL)
        {
            printf("%d\t",ptr -> data);
            ptr = ptr -> next;
        }
    }
    printf("\n");
}

int main()
{
    insertEnd(100);
    insertEnd(200);
    insertEnd(300);
    insertEnd(400);
    insertEnd(500);

    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

    deleteEnd();
    display();

}


/*

    100     200     300     400     500
    100     200     300     400
    100     200     300
    100     200
    100
    List is Empty ...
    List is Already Empty...

*/