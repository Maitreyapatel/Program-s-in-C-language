#include <stdio.h>
#include <stdlib.h>
struct node {
            int data;
            struct node *next;
                };
struct node *start=NULL;

void beg(int a)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));


        p->data=a;
        p->next=start;
        start=p;

}
void end(int a)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    struct node *temp=start;

    while(temp->next!=NULL)
        temp=temp->next;

    p->data=a;
    p->next=NULL;
    temp->next=p;

    //printf("\n%d",p->data);
}
void print()
{
    struct node *temp=start;

    while(temp->next!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
    printf("%d",temp->data);
    printf("\n");
}
void sort()
{
    struct node *temp=start,*coun;
    int i,j,n,sorted,t;
    n=count(start);


    /*for(i=0;i<n-1 && !sorted;i++)
    {
       // temp=start;
        sorted=1;
        for(j=0;j<n-i-1;j++)
        {
            if(temp->data>(temp->next)->data)
            {
                t=temp->data;
                temp->data=(temp->next)->data;
                (temp->next)->data=t;
                sorted=0;
            }
            temp=temp->next;
        }
    }*/

    	for( ; temp->next != NULL; temp = temp->next)
	{
		for(coun = temp->next; coun != NULL; coun = coun->next)
		{
			if(temp->data > coun->data)
			{
				t = temp->data;
				temp->data = coun->data;
				coun->data = t;
			}
		}
	}
}
int count(struct node *temp)
{
    //struct node *temp=start;
    if(temp==NULL)
        return 0;
    else
        return (1+count(temp->next));
}
void prev(struct node *cur)
{


    if(cur==NULL)
        return ;
    else
        prev(cur->next);

    printf(" %d ",cur->data);
}
void mid(int a,int n)
{
    int i;
    struct node *temp=start;
    for(i=0;i<n;i++)
    {
        if(temp->next!=NULL)
            temp=temp->next;
    }
    struct node *p=(struct node *)malloc(sizeof(struct node));

    p->data=a;
    p->next=temp->next;
    temp->next=p;
}
int main()
{
    int c,a,n;

    while(1)
    {
    printf("1.for begin\n2.for mid\n3.for end\n4.for print\n5.for exit\n6.for sort\n7.for print reverse\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("\nEnter the number");
        scanf("%d",&a);

        beg(a);
        break;
    case 2:
        printf("\nEnter the number and position");
        scanf("%d %d",&a,&n);

        mid(a,n-1);
        break;
    case 3:
        printf("\nEnter the number");
        scanf("%d",&a);

        end(a);
        break;
    case 4:
        print();
        break;
    case 5:
        exit(1);
    case 6:
        sort();
        break;
    case 7:
       // struct node *cur=start;
        prev(start);
        break;
    }
    }
    return 0;
}
