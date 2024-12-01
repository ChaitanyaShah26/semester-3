// Selection Sort

#include<stdio.h>
#include<conio.h>
#define MAX 100

void selectionSort(int a[], int n);
void main()
{
    int n,i,a[MAX];
    clrscr();
    printf("Enter Number of Element to be Sort: ");
    scanf("%d",&n);
    printf("\n Enter %d Elements in Array to Sort: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Elements Before Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    selectionSort(a,n);
    printf("\n Elements after Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

    getch();
}

void selectionSort(int a[], int n)
{
    int i,j,position,swap;

    for(i = 0; i < n - 1; i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[position] > a[j])
            position=j;
        }
        if(position != i)
        {
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }
}