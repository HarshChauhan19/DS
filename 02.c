// Write a menu driven program to create a dynamic list using dynamic memory allocation functions
// (malloc(), calloc(), realloc() and free()). First program should ask the user to input the initial size of
// the list and then give a menu to add or delete the elements in the list. The program should have
// following menus.1)Add an element 2) Delete last element 3) Display the list elements 4) Reset

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *list = NULL;
    int size = 0;
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add an element\n");
        printf("2. Delete last element\n");
        printf("3. Display the list elements\n");
        printf("4. Reset\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            size++;
            list = (int *)realloc(list, size * sizeof(int));
            printf("Enter the element : ");
            scanf("%d", &list[size - 1]);
            break;
        case 2:
            if (size > 0)
            {
                size--;
                list = (int *)realloc(list, size * sizeof(int));
                printf("Last element deleted.\n");
            }
            else
            {
                printf("The list is empty.\n");
            }
            break;
        case 3:
            printf("List elements: ");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", list[i]);
            }
            printf("\n");
            break;
        case 4:
            free(list);
            list = NULL;
            size = 0;
            printf("List reset.\n");
            break;
        case 5:
            if (list != NULL)
            {
                free(list);
            }
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;