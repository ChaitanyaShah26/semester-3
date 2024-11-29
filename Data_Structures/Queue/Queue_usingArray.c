#include<stdio.h>
#include<conio.h>
#define Max 5

int queue[Max];
int f=-1;
int r=-1;

void Enqueue(int num)
{
	if(r==Max-1)
	{
		printf("\nQueue is Full\n");
	}
	else if(f==-1 && r==-1)
	{
		f++;
		r++;
		queue[r]=num;
	}
	else
	{
	   r++;
	   queue[r]=num;
	}
}

void Dequeue()
{
	if(f==-1 || f>r)
	{
		printf("\nQueue is Empty\n");
	}
	else
	{
		printf("\nThe no. is : %d\n",queue[f]);
		f=f+1;
	}
}

void display()
{
	if(f==-1 || f>r)
	{
		printf("\nQueue is Empty\n");
	}
	else
	{
		int i;
		printf("\n");
		for(i=f;i<=r;i++)
		{
			printf("%d\t",queue[i]);
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