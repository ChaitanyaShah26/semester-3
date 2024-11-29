#include<stdio.h>
#include<conio.h>

struct Node* createNode(int);

struct Node
{
	int data;
	struct Node* next;
};

struct Node *node,*tos=NULL,*temp=NULL;

struct Node* createNode(int info)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node -> data=info;
	node -> next=NULL;
	return node;
}

void push(int info)
{
	node=createNode(info);
	if(tos==NULL)
	{
		tos=node;
	}
	else
	{
		node -> next=tos;
		tos=node;
	}
}

void pop()
{
	if(tos==NULL)
	{
		printf("\nStack is Empty!");
	}
	else
	{
		temp=tos;
		tos=tos -> next;
		printf("%d",temp->data);
		free(temp);
	}
}

void stackTop()
{
	if(tos==NULL)
	{
		printf("\nStack is Empty!");
	}
	else
	{
		printf("%d",tos->data);
	}
}

void display()
{
	if(tos==NULL)
	{
		printf("\nStack is Empty!");
	}
	else
	{
		temp=tos;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp -> next;
		}
	}
}

void main()
{
	int info,op;
	clrscr();
	do
	{
		printf("\nEnter choice no. to perform operations:\n");
		printf("\n1) Push\n2) Pop\n3) StackTop\n4) Display\n5) EXIT\n\tYour Choice number : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				printf("\nEnter number to Push in Stack : ");
				scanf("%d",&info);
				push(info);
				break;

			case 2:
				printf("\nPopped element from Stack : ");
				pop();
				break;

			case 3:
				printf("\nTop element of Stack : ");
				stackTop();
				break;

			case 4:
				printf("\nElements in the Stack : \n\t");
				display();
				break;

			case 5:
				exit();
				break;

			default:
				printf("\n\tEnter a valid choice number!");
		}
	} while(op!=5);	
	getch();
}