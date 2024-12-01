// Linear Search

#include<stdio.h>
#include<conio.h>

void main() {
    int i, length, num, pos;

    clrscr();

    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];

    printf("\nEnter the array : ");
    for(i=0 ; i<length ; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to be searched : ");
    scanf("%d", &num);

    i=0;
    while(i < length) {
        if(arr[i] == num) 
            pos = i;
        i++;
    }

    if(pos >= 0)
        printf("\nElement %d found at position : %d", num, (pos+1));
    else    
        printf("\nElement not found");

    getch();
}