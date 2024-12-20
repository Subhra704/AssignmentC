#include <stdio.h>

void sort_array_parts(int arr[], int size)
{
    // Find the middle index
    int mid = size / 2;

    // Sort the first half in descending order
    for (int i = 0; i < mid - 1; i++)
    {
        for (int j = 0; j < mid - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Sort the second half in ascending order
    for (int i = mid; i < size - 1; i++)
    {
        for (int j = mid; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elements of the array -> ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr,n);
    printf("\n");

    sort_array_parts(arr, n);

    printf("Sorted array: ");
    printArray(arr,n);
    printf("\n");

    return 0;
}