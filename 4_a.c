// Write a menu driven program for Stack that performs following operation using array.1)PUSH 2)
// POP 3) PEEP 4) DISPLAY

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow. Cannot push more elements.\n");
    }
    else
    {
        stack[++top] = value;
        printf("Element %d pushed onto the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty. Cannot pop.\n");
    }
    else
    {
        printf("Popped element : %d\n", stack[top--]);
    }
}

void peep()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Top element : %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Stack Elements : ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to PUSH : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}