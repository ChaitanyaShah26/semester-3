// Bubble Sort

#include<stdio.h>
#include<conio.h>
#define MAX 100

void bubbleSort(int a[],int n);

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
    bubbleSort(a,n);
    getch();
}


void bubbleSort(int a[],int n)
{
    int i,j,temp;
    printf("\n Array Before Sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    //Logic for Bubble Sort
    for(i=0;i<n-1;i++) //loop for number of passes
        {
            for(j=0;j<n-1-i;j++)
                {
                    if(a[j]<a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }

                }

        }
      printf("\n Array After Sorting:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);

}