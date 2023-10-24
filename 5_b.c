#include <stdio.h>
#define size 10

int cqueue[size];
int front = -1;
int rear = -1;

void insert()
{
    int item;
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Queue Overflow !! \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    printf("Enter an Element : ");
    scanf("%d",&item);
    cqueue[rear] = item;
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow !!\n");
        return;
    }
    printf("Deleted Element is %d\n",cqueue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty !!\n");
        return;
    }
    printf("Queue Elements : ");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    else
    {
        for (i = front; i < size - 1; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i < rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}