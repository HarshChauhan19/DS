#include <stdio.h>

void readArray(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int calculateSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float calculateAverage(int sum, int n)
{
    return (float)sum / n;
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int arr[10];
    int choice;
    int sum;
    float avg;
    int max;
    int min;
    readArray(arr, 10);
    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Average\n");
    printf("3. Maximum Value\n");
    printf("4. Minimum Value\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sum = calculateSum(arr, 10);
        printf("Sum of elements: %d\n", sum);
        break;
    case 2:
        sum = calculateSum(arr, 10);
        avg = calculateAverage(sum, 10);
        printf("Average of elements: %.2f\n", avg);
        break;
    case 3:
        max = findMax(arr, 10);
        printf("Maximum value: %d\n", max);
        break;
    case 4:
        min = findMin(arr, 10);
        printf("Minimum value: %d\n", min);
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}