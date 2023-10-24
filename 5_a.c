#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void insert()
{
    int data;
    if (rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue is full. Cannot insert.\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &data);
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d inserted into the queue.\n", data);
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is empty. Nothing to delete.\n");
    }
    else
    {
        int deletedItem = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        printf("%d deleted from the queue.\n", deletedItem);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty. Nothing to display.\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    
    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}