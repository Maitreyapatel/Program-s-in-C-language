#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
            int data;
            NODE *next;
                };
NODE *start=NULL;
void print(NODE *temp)
{

    while(temp)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(NODE *head)
{
    NODE *prev = NULL;
    NODE *next;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    print(prev);
}

int main()
{
    int c=1,n;
    NODE *temp;
    while(c==1)
    {
        printf("\nfor exit press 0 else press 1\n");
        scanf("%d",&c);

        if(c==0)
            break;
        printf("\nEnter data:\n");
        scanf("%d",&n);

        NODE *p=(NODE *)malloc(sizeof(NODE));

        if(start==NULL)
        {
            p->data=n;
            p->next=NULL;
            start=p;
            temp=start;
        }
        else
        {
            p->data=n;
            p->next=temp->next;
            temp->next=p;
            temp=temp->next;
        }


    }

    printf("\nlinked list before reversed:\n");
    print(start);
    printf("\nlinked list after reversed:\n");
    reverse(start);


    return 0;
}



//reference  http://stackoverflow.com/questions/1801549/reverse-a-singly-linked-list
