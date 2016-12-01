#include <stdio.h>
#include<stdlib.h>
struct node {
			int data;
			struct node *left,*right;
};
struct node *root=NULL,*t1,*t2;
void add(struct node *head,struct node *p)
{
	if(root==NULL)
	{
		root=p;head=root;
	}
	else if ((p->data > head->data) && (head->right != NULL))      /* value more than root node value insert at right */
        add(head->right,p);
    else if ((p->data > head->data) && (head->right == NULL))
        head->right = p;
    else if ((p->data < head->data) && (head->left != NULL))    /* value less than root node value insert at left */
        add(head->left,p);
    else if ((p->data < head->data) && (head->left == NULL))
        head->left = p;
}
void search(struct node *temp,int num)
{
    if(temp->data>num)
    {
        if(temp->data==num)
            printf("\nOh...!!!Your number is in our data.\n");
        else if(temp->left==NULL)
            printf("\nOh...!!!Your number is not in our data.\n");
        else
            search(temp->left,num);
    }

    else if (temp->data<=num)
    {
        if(temp->data==num)
            printf("\nOh...!!!Your number is in our data.\n");
        else if(temp->right==NULL)
            printf("\nOh...!!!Your number is not in our data.\n");
        else
            search(temp->right,num);
    }
}
void delete()
{
	int num;

	if(root==NULL)
	{
		printf("\nTree is empty:\n");
		return ;
	}

	printf("\nEnter the data to delete:\n");
	scanf("%d",&num);

	t1=root;
	t2=root;

	search1(root,num);

}
void search1(struct node *t,int data)
{
	if(data>t->data)
	{
		t1=t;
		search1(t->right,data);
	}
	else if (data<t->data)
	{
		t1=t;
		search(t->left,data);
	}
	else if(data==t->data)
		delete1(t);
}
void delete1(struct node *t)
{
	int k;

	if(t->left==NULL && t->right==NULL)
	{
		if(t1->left==t)
		{
			t1->left=NULL;
		}
		else
			t1->right=NULL;
		t=NULL;
		free(t);
		return ;
	}

	else if(t->right==NULL)
	{
		if(t1==t)
		{
			root=t->left;
			t1=root;
		}
		else if(t1->right==t)
		{
			t1->right=t->left;
		}
		else
			t1->left=t->left;

		t=NULL;
		free(t);
		return ;
	}
	else if(t->left==NULL)
	{
		if(t1==t)
		{
			root=t->right;
			t1=root;
		}
		else if(t1->left==t)
		{
			t1->left=t->right;
		}
		else
			t1->right=t->right;

		t=NULL;
		free(t);
		return ;
	}

	else if(t->left!=NULL && t->right!=NULL)
	{
		t2=root;
		if(t->right!=NULL)
		{
			k=smallest(t->right);
		}
		else
			k=largest(t->left);

		search1(root,k);
		t->data=k;
	}
}
void smallest(struct node *t)
{
	t2=t;
	if(t->left!=NULL)
	{
		t2=t;
		return (smallest(t->left));
	}
	else
		return (t->data);
}
void largest(struct node *t)
{
	if(t->right!=NULL)
	{
		t2=t;
		return (largest(t->right));
	}
	else
		return (t->data);
}
void print(struct node *temp)
{
	if (temp != NULL) {
      print(temp->left);
      printf("%d ", temp->data);
      print(temp->right);
	}
}
int main(void) {
	// your code goes here
	int i=1,num;

	while(1)
	{
		printf("\n1.for enter data\n2.for print\n3.for search data\n4.for exit\n5.for delete\n");
		scanf("%d",&i);
		switch (i)
		{
			case 1:

			printf("\nEnter the data\n");
			scanf("%d",&num);

			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->data=num;
			p->left=NULL;
			p->right=NULL;
			add(root, p);

			break;

			case 2:
			print (root);
			break;

			case 3:
            printf("\nEnter the number:\n");
            scanf("%d",&num);
			search(root,num);
			break;

			case 4:
			exit(1);

			case 5:
			delete();
			break;
		}
	}


	return 0;
}
