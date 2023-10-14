#include<stdio.h>
#include<conio.h>

void PUSH(int A[],int TOP ,int SIZE)
{
    if (TOP==SIZE-1)
    {
        printf("Overflow");
    }
    else
    {
        TOP++;
        printf("ENter an Elements : ");
        scanf("%d",A[TOP]);
    }
}