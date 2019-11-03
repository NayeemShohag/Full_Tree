#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int value;
	tree *left;
	tree *right;
}*head;

void create(int x)
{
	struct  tree *temp,*temp1;
	int flag=0;
	if(head==NULL)
	{
		head=(tree*)malloc(sizeof(tree));
		head->value=x;
		head->left=NULL;
		head->right=NULL;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(x>temp->value)
		{
			temp1=temp;
			temp=temp->right;
			flag=0;
		}
		else if(x<temp->value)
		{
			temp1=temp;
			temp=temp->left;
			flag=1;
		}
		else
		{
			temp1=temp;
			temp=temp->right;
			flag=0;
		}
	}
	temp=(tree*)malloc(sizeof(tree));
	temp->value=x;
	temp->left=NULL;
	temp->right=NULL;
	if(flag==0)
	{
		temp1->right=temp;
	}
	else
	{
		temp1->left=temp;
	}
}
void in(tree *base)
{
	if(base!=NULL)
	{
		in(base->left);

		printf("%d ",base->value);
		in(base->right);

	}
}
void pre(tree *base)
{
	if(base!=NULL)
	{
		printf("%d ",base->value);
		in(base->left);
		in(base->right);

	}
}
void post(tree *base)
{
	if(base!=NULL)
	{

		in(base->left);
		in(base->right);
		printf("%d ",base->value);

	}
}

void min()
{
	tree *temp;
	temp=head;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	printf("%d is minimum\n",temp->value);


}
void search(int x)
{
	tree *temp;
	temp=head;
	if(x==temp->value)
	{
		printf("found\n");
		return;
	}
	while (temp != NULL)
	{
		if (x > temp->value)
		{
			temp = temp->right;
		}
		else if (x<temp->value)
		{
			temp = temp->left;
		}
		else if (x == temp->value)
		{
			printf("found");
			break;
		}

	}
	if (temp == NULL)
	{
		printf("not found");
	}
}


void main()
{
	int value=0,choice=0;

	while(1)
	{
		printf("\n1->INSERT\n");
		printf("2->INORDER\n");
		printf("3->PREORDER\n");
		printf("4->POSTORDER\n");
		printf("5->MINIMUM\n");
		printf("6->SEARCH\n");


		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			printf("Enter the value\n");
			scanf("%d", &value);
			create(value);
			printf("Value Inserted\n");
			break;
		case 2:
			in(head);
			break;
		case 3:
			pre(head);
			break;
		case 4:
			post(head);
			break;
		case 5:
			min();
			break;
		case 6:
			printf("Enter the value\n");
			scanf("%d", &value);
			search(value);
			break;
		default:
			break;
		}

	}


}