// Fibonacci Search

#include<stdio.h>
#include<conio.h>

int arr[100];
int fib[10]={0,1,1,2,3,5,8,13,21,34};
int fiboSearch(int *a,int n,int *f,int s);
int findMin(int a,int b);

void main()
{
    int i,n,s,location=-1;
    clrscr();
    printf("\nEnter Number of Elements in array:");
    scanf("%d",&n);
    printf("\nEnter %d Elements in Array:",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\n Enter Element to be search in array:");
    scanf("%d",&s);
    location=fiboSearch(arr,n,fib,s);
    if(location !=0)
        printf("\n Element %d Found at location %d",s,location);
    else
        printf("\n Element Not Found");

    getch();
}

int fiboSearch(int *a,int n,int *f,int s)
{
    int k=0,offset=-1,i;
    while(f[k]<=n)
        k++;

    while(f[k]!=0)
    {
        i=findMin(offset+f[k-2],n-1);
        if(s==a[i])
            return i;
        else if(s>a[i])
        {
            k=k-1;
            offset=i;
        }
        else
        {
            k=k-2;
        }
    }
    return 0;
}

int findMin(int a,int b)
{
    int min;
    if(a<b)
    {
        min=a;
    }
    else
    {
        min=b;
    }
    return min;
}
