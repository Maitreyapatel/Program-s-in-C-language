#include <stdio.h>
#include<stdlib.h>
struct node{
            int data;
            struct node *next;
            struct node *prev;
};
struct node *start=NULL;
void adend()
{
		struct node *temp;
 		struct node *p=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the number:\n");
            scanf("%d",&p->data);

            if(start==NULL)
            {
                p->next=NULL;
                p->prev=NULL;
                start=p;
            }
            else
            {
                temp=start;
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                p->next=NULL;
                p->prev=temp;
                temp->next=p;
            }
}
void rev()
{
	struct node *temp;
printf("\nPrint in reverse order:\n");

        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;

        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->prev;
        }
}
void admid()
{
	int i,po;
	struct node *temp=start,*p=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data and position where to add:\n");
	scanf("%d%d",&p->data,&po);

	for(i=1;i<po;i++)
		temp=temp->next;

	p->next=temp->next;
	p->prev=temp;
	(temp->next)->prev=p;
	temp->next=p;
}
void print()
{
 	struct node *temp=start;

	while(temp->next!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
	printf("\n");
}
void delete()
{
	struct node *temp=start,*temp1;
	int num;

	printf("\nEnter the data that you want to delete:\n");
	scanf("%d",&num);

	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			temp1=temp;
			break;
		}
		temp=temp->next;
	}

	(temp->prev)->next=temp->next;
	(temp->next)->prev=(temp->prev);
	printf("1");
	free(temp1);
}

int main(void) {

	int i,n;
	while(1)
	{
		printf("\n1.for add data at the end\n2.for add data at position\n3.for print reverse\n4.for delete\n5.for print\n6.for exit\n");
	    	scanf("%d",&i);

		if(i==1)
			adend();
		else if(i==2)
			admid();
		else if(i==3)
			rev();
		else if(i==4)
			delete();
		else if(i==5)
			print();
		else if(i==6)
			break;
	}

	return 0;
}
