// Write a program to implement stack and queue using linked list.

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

struct Stack
{
    struct Node *top;
};
void printstack(struct Stack *stack)
{
    struct Node *current = stack->top;
    printf("Stack : ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push(struct Stack *stack, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void printqueue(struct Queue *queue)
{
    struct Node *current = queue->front;
    printf("Queue : ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue Underflow.\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int main()
{
    int ch, number;
    struct Stack stack;
    struct Queue queue;
    stack.top = NULL;
    queue.front = queue.rear = NULL;

    while (1)
    {
        printf("1) Stack.\n");
        printf("2) Queue.\n");
        printf("3) Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("1) PUSH.\n");
            printf("2) POP.\n");
            printf("3) DISPLAY.\n");

            printf("Enter your choice : ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("Enter value : ");
                scanf("%d", &number);
                push(&stack, number);
                break;

            case 2:
                number = pop(&stack);
                printf("Popped from stack : %d\n", number);
                break;

            case 3:
                printstack(&stack);
                break;

            default:
                printf("Invalid Choice!\n");
                break;
            }
            break;

        case 2:
            printf("1) Enqueue.\n");
            printf("2) Dequeue.\n");
            printf("3) Display.\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("Enter value : ");
                scanf("%d", &number);
                enqueue(&queue, number);
                break;

            case 2:
                number = dequeue(&queue);
                printf("Dequeued from queue : %d\n", number);
                break;

            case 3:
                printqueue(&queue);
                break;

            default:
                printf("Invalid choice.\n");
                break;
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}