#include<stdio.h>
#include<conio.h>
#define MAX 5

void push(int n);
void pop();
void display();
int tos=-1,stack[MAX];

void main()
{
	int choice=1,n;

    clrscr();

	do
	{
		printf("\n\n---- STACK using Arrays ----\n\n");
		printf("\nEnter your choice:\n");
		printf("\n1. Push\n2. Pop\n3. Display\n4. EXIT\n\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		    case 1:
		        printf("\nEnter number to push in stack : \n");
		        scanf("%d",&n);
		        push(n);
		        display();
		        break;
	        
	        case 2:
		        pop();
		        display();
		        break;
		        
	        case 3:
	            display();
		        break;
		        
	        case 4:
	            exit(0);
		        break;
		    
		    default:
		        printf("\n**** Invalid Choice! ****\nEnter valid Choice!");
		}
		
	} while(choice!=4);

	getch();
}


void push(int n)
{
    if(tos==(MAX-1))
    {   
        printf("\nStack is full....\n\tPush is not possible!\n");
    }
    else
    {
        tos++;
        stack[tos]=n;
    }
}

void pop()
{
    if(tos==-1)
    {
        printf("\nStack is empty....\n\tCannot pop from stack!\n");
    }
    else
    {
        printf("\nPopped element is %d.\n",stack[tos]);
        tos--;
    }
}

void display()
{
    int i;
    if(tos==-1)
    {
        printf("\nStack is empty....\n\tCannot display stack!\n");
    }
    else
    {
        printf("\nCurrent Stack is :\n");
        for(i=tos;i>-1;i--)
        {
            printf("\t|\t%d\t|\n",stack[i]);
        }
    }
}