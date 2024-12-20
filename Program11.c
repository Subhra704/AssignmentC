#include <stdio.h>
#include <stdlib.h>

void calculateAverageAndMedian(int *arr, int n, double *average, double *median)
{
    int sum = 0;

    // Calculate the sum for average
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    *average = (double)sum / n;

    // Sort the array for median calculation
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculate median
    if (n % 2 == 0)
    {
        *median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        *median = arr[n / 2];
    }
}

int main()
{
    int n;
    double average, median;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input numbers
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calculate average and median
    calculateAverageAndMedian(arr, n, &average, &median);

    // Output results
    printf("Average: %.2f\n", average);
    printf("Median: %.2f\n", median);

    // Free the allocated memory
    free(arr);

    return 0;
}
