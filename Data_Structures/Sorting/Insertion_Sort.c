// Insertion Sort

#include<stdio.h>
#include<conio.h>
#define MAX 100

void insertionSort(int arr[], int n);
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
    insertionSort(a,n);
    printf("\n Elements after Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

    getch();
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1],
    // that are greater than key, to one
    // position ahead of their
    // current position
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
    }
}