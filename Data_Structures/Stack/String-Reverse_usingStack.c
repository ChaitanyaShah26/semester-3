#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 100

void push(char ch);
char pop();
int tos=-1;
char stack[MAX];

void main()
{   
    int i;
    char str[100],ch,str_rev[100];

    clrscr();

    printf("\nEnter a string: \n");
    fflush(stdin);
    gets(str);

    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }

    for(i=0;i<strlen(str);i++)
    {
        str_rev[i]=pop();
    }

    printf("\nString after reverse is : %s",str_rev);

    getch();
}


void push(char ch)
{
    if(tos==(MAX-1))
    {  
        printf("\nStack Overflow!\n");
    }
    else
    {
        tos++;
        stack[tos]=ch;
    }
}

char pop()
{
    if(tos==-1)
    {
        printf("\nStack Underflow!\n");
        return 0;
    }
    else
    {
        tos--;
        return stack[tos+1];
    }
}