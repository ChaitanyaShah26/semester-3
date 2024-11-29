#include<stdio.h>
#include<conio.h>
#define Max 5

int queue[Max];
int f=-1;
int r=-1;

void Enqueue(int num)
{
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		queue[r]=num;
	}
	else if((r+1)%Max==f)
	{
		printf("\nThe Queue is full\n");
	}
	else
	{
		r=(r+1)%Max;
		queue[r]=num;
	}
}

void Dequeue()
{
	if(f==-1 && r==-1)
	{
		printf("\nQueue is Empty\n");	
	}
	else if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
	{
		printf("\nDeleted Element of the Queue : %d",queue[f]);
		f=(f+1)%Max;
	}
}

void display()
{
	int i;
	printf("\n");
	if (f>r)
	{
		for (i = f; i < Max; i++)
		{
			printf("%d ", queue[i]);
		}
		for (i = 0; i <= r; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	else
	{
		for (i = f; i <= r; i++)
		{
			printf("%d ", queue[i]);
		}
	}
}

void main()
{
	int num,ch;
	clrscr();
	do
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter no to be put in queue : ");
				scanf("%d",&num);
				Enqueue(num);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Enter valid choice!!\n");
		}
	}while(ch!=4);
	getch();
}