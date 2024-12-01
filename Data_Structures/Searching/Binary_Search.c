// Binary Search

#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[100],i, b,e,mid,n,t;
    clrscr();
    printf("Enter Number of elements in array: ");
    scanf("%d",&n);

    printf("\nEnter %d Elements in Array: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter Element to be search: ");
    scanf("%d",&t);
    b=0;
    e=n-1;
    while(b<=e)
    {
        mid=(b+e)/2;
        if(t<arr[mid])
            e=mid-1;
        else if(t>arr[mid])
            b=mid+1;
        else
            b=e+1;
    }
    if(t==arr[mid])
        printf("\nElement %d found at %d Location",t,mid);
    else
        printf("\n Element Not Found...");
    getch();

}
