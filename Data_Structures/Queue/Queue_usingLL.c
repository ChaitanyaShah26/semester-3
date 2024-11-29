#include<stdio.h>
#include<conio.h>

struct Node* createNode(int);

struct Node
{
	int data;
	struct Node* next;
};

struct Node *node,*front=NULL, *rear=NULL, *temp=NULL;

struct Node* createNode(int info)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node -> data=info;
	node -> next=NULL;
	return node;
}

void Enqueue(int info)
{
	node=createNode(info);
	if(front==NULL && rear==NULL)
	{	
		front=node;
		rear=node;
	}
	else 
	{
		rear -> next=node;
		rear=node;
	}
}

void Dequeue()
{
	if(front==NULL && rear==NULL)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		temp=front;
		front=front -> next;
		printf("%d",temp->data);
		free(temp);
	}
}

void QueueFront()
{
	if(front==NULL && rear==NULL)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		printf("%d",front->data);
	}
}

void QueueRear()
{
	if(front==NULL && rear==NULL)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		printf("%d",rear->data);
	}
}

void display()
{
	if(front==NULL && rear==NULL)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
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
		printf("\n1) Enqueue\n2) Dequeue\n3) QueueFront\n4) QueueRear\n5) Display\n6) EXIT\n\tYour Choice number : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				printf("\nEnter number to Enqueue in Queue : ");
				scanf("%d",&info);
				Enqueue(info);
				break;

			case 2:
				printf("\nDequeued element from Queue : ");
				Dequeue();
				break;

			case 3:
				printf("\nFirst element of Queue : ");
				QueueFront();
				break;

			case 4:
				printf("\nLast in the Queue : \n\t");
				QueueRear();
				break;

			case 5:
				printf("\nElements in the Queue : \n\t");
				display();
				break;

			case 6:
				exit();
				break;

			default:
				printf("\n\tEnter a valid choice number!");
		}
	} while(op!=6);	
	getch();
}