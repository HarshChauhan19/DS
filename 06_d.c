// Write a menu driven program to implement following operations on circular singly linked
// list.1)Insert a node at the end of the linked list. 2)Insert a node before specified position. 3)Delete
// first node in the linked list. 4)Delete a node after specified position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBeforePosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
            if (temp == *head)
            {
                printf("Invalid position\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (position == 1)
        {
            *head = newNode;
        }
    }
}

void deleteFirstNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        if (*head == temp)
        {
            free(temp);
            *head = NULL;
        }
        else
        {
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
    }
}

void deleteAfterPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 1; i < position; i++)
        {
            temp = temp->next;
            if (temp == *head)
            {
                printf("Invalid position\n");
                return;
            }
        }
        struct Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    do
    {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert before specified position\n");
        printf("3. Delete first node\n");
        printf("4. Delete after specified position\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position before which to insert: ");
            scanf("%d", &position);
            insertBeforePosition(&head, data, position);
            break;

        case 3:
            deleteFirstNode(&head);
            break;

        case 4:
            printf("Enter position after which to delete: ");
            scanf("%d", &position);
            deleteAfterPosition(&head, position);
            break;

        case 5:
            display(head);
            break;

        case 0:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice, please try again\n");
        }

    } while (choice != 0);

    return 0;
}
