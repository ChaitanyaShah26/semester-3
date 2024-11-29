// WAP in C to evaluate postfix expression

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

int stack[MAX];
int tos=-1;

void push(int n);
int pop();

void main()
{
	char postfix[MAX];
	int i=0,a,b;
	clrscr();

	printf("\nEnter a Postfix expression to evaluate : ");
	fflush(stdin);
	gets(postfix);

	while(postfix[i] != '\0')
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i]-'0');
		}
		else
		{
			a=pop();
			tos--;
			b=pop();
			tos--;
			switch(postfix[i])
			{
				case '+':
					push(b+a);
					break;

				case '-':
					push(b-a);
					break;

				case '*':
					push(b*a);
					break;

				case '/':
					push(b/a);
					break;
			}
		}
		i++;
	}

	printf("\nValue of the entered postfix expression is : %d",pop());
	printf("\n\n\t %s  =  %d\n",postfix,pop());

	getch();
}

void push(int n)
{
	tos++;
	stack[tos]=n;
}

int pop()
{
	return (stack[tos]);
}