// WAP in C to convert Infix expression to Postfix expression

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int tos=-1;

void push(char ch);
char pop();
int precedence(char ch);

void main()
{
	char infix[MAX];
	char ch;
	int i=0;
	clrscr();
	printf("\nEnter Infix Expression : ");
	fflush(stdin);
	gets(infix);

	printf("\nPostfix Expression : ");

	while(infix[i] != '\0')
	{
		if(isalnum(infix[i]))
			printf("%c ",infix[i]);
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while((ch=pop())!='(')
			{
				printf("%c ",ch);
			}
		}
		else
		{
			while(precedence(stack[tos]) >= precedence(infix[i]))
			{
				printf("%c ",pop());
			}
			push(infix[i]);
		}
		i++;
	}

	while(tos != -1)
	{
		printf("%c ",pop());
	}

	getch();
}

void push(char ch)
{
	tos++;
	stack[tos]=ch;
}

char pop()
{
	if(stack[tos]==-1)
		return -1;
	else
		return stack[tos--];
}

int precedence(char ch)
{
	if(ch=='(')
		return 0;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
	return 0;
}