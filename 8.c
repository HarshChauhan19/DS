// Write a menu driven program to implement following searching methods. 1)Linear Searching
// 2)Binary Searching

#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int choice, size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            int linearResult = linearSearch(arr, size, key);
            if (linearResult != -1)
            {
                printf("Element found at index %d\n", linearResult);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            int binaryResult = binarySearch(arr, size, key);
            if (binaryResult != -1)
            {
                printf("Element found at index %d\n", binaryResult);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}