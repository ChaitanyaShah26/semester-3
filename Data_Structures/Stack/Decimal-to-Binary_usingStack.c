#include<stdio.h>
#include<conio.h>
#define MAX 100

void push(int n);
void pop();
int tos=-1;
int stack[MAX];

void main()
{
    int num,digit=0,i;
    clrscr();
	
    printf("\n---- Decimal to Binary ----\n");
    printf("\nEnter a number to convert :\n");
    scanf("%d",&num);
    
    while(num>=1)
    {
        push(num%2);
        num=num/2;
        digit++;
    }
    
    printf("\nThe number in Binary form is :\t");
    for(i=0;i<digit;i++)
    {
        pop();
    }
    
	getch();
}


void push(int n)
{
    if(tos==(MAX-1))
    {  
        printf("\nStack Overflow!\n");
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
        printf("\nStack Underflow!\n");
    }
    else
    {
        printf("%d",stack[tos]);
        tos--;
    }
}