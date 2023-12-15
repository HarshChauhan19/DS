// Write a menu driven program to implement following operations on doubly linked list.1)Insert a
// node at the front of the linked list. 2)Insert a node at the end of the linked list. 3)Delete a last node
// of the linked list 4)Delete a node before specified position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int info;
    struct Node *next;
} *head = NULL;

void pushFront()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->prev = NULL;
    printf("\nEnter data for the node to be inserted at front : ");
    scanf("%d", &node->info);
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = head;
        // node->prev=head->prev;
        head->prev = node;
        head = node;
    }
}

void pushAtPosition()
{
    int pos = 0, count = 0;
    struct Node *temp = head, *temp1 = NULL;

    printf("\nEnter position where you want to insert an element : ");
    scanf("%d", &pos);

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (pos <= 0 || pos > count)
    {
        printf("\nInvalid position entered.");
        return;
    }
    else if (pos == 1)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->prev = NULL;
        printf("\nEnter data for the node to be inserted at position %d : ", pos);
        scanf("%d", &node->info);

        node->next = head;
        head->prev = node;
        head = node;
    }
    else
    {
        count = 0;
        temp = head;
        while (count < pos - 2)
        {
            temp = temp->next;
            count++;
        }

        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data for the node to be inserted at position %d : ", pos);
        scanf("%d", &node->info);

        node->prev = temp;
        node->next = temp->next;
        temp->next->prev = node;
        temp->next = node;
    }
}

void pushEnd()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->prev = NULL;
    printf("\nEnter data for the node to be inserted at end : ");
    scanf("%d", &node->info);
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void popFront()
{
    if (head == NULL)
    {
        printf("\nDoubly linked list is empty.");
    }
    else
    {
        struct Node *temp = head;
        printf("\nDeleted element is : %d.", head->info);
        head->next->prev = NULL;
        head = head->next;
        free(temp);
    }
}

void popEnd()
{
    if (head == NULL)
    {
        printf("\nDoubly linked list is empty.");
    }
    else if (head->next == NULL)
    {
        printf("\nDeleted element is : %d.", head->info);
        head = NULL;
    }
    else
    {
        struct Node *temp = head, *previous = NULL;
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        printf("\nDeleted element is : %d.", temp->info);
        previous->next = NULL;
        free(temp);
    }
}

void popAtPosition()
{
    int pos = 0, count = 0;
    struct Node *temp = head, *temp1 = NULL;
    if (head == NULL)
    {
        printf("\nDoubly linked list is empty.");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("\nEnter position on which you want to delete an element : ");
        scanf("%d", &pos);
        if (pos <= 0 || pos > count)
        {
            printf("\nElement doesnot exist.");
        }
        else if (pos == 1)
        {
            temp1 = head;
            printf("\nDeleted element is : %d", head->info);
            head->next->prev = NULL;
            head = head->next;
            free(temp1);
        }
        else
        {
            count = 0;
            temp = head;
            while (count < pos - 2)
            {
                temp = temp->next;
                count++;
            }
            temp1 = temp->next;
            printf("\nDeleted element is : %d", temp1->info);
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nDoubly linked list is empty.");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf(" %d ", temp->info);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch = 0;
    do
    {
        printf("\nEnter 1. to Insert node at the front of the Doubly List.");
        printf("\nEnter 2. to Insert node at the specific position in the Doubly List.");
        printf("\nEnter 3. to Insert node at the end of the Doubly List.");
        printf("\nEnter 4. to Delete first node from the Doubly List.");
        printf("\nEnter 5. to Delete the node at specified position in the Doubly List.");
        printf("\nEnter 6. to Delete last node from the Doubly List.");
        printf("\nEnter 7. to Display the Doubly List.");
        printf("\nEnter 8. to exit.");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            pushFront();
            break;
        case 2:
            pushAtPosition();
            break;
        case 3:
            pushEnd();
            break;
        case 4:
            popFront();
            break;
        case 5:
            popAtPosition();
            break;
        case 6:
            popEnd();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid option selected.");
        }
    } while (ch >= 1 && ch <= 8);
    return 0;
}