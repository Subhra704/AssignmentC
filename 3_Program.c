#include <stdio.h>
#include <string.h>

void Strrev(char str[], char rev[], int n)
{
    int i;
    n--;
    for (i = 0; str[i] != '\0'; i++, n--)
    {
        rev[i] = str[n];
    }
    rev[i] = '\0';
    printf("\nThe reversed string: %s", rev);
}

void revRecursive(char str[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    revRecursive(str, start + 1, end - 1);
}

int main()
{
    char str[100], rev[100];
    int ch, n;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    if (str[strlen(str) - 1] = '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
    n = strlen(str);
    // Strrev(str, rev, n);
    revRecursive(str, 0, strlen(str) - 1);
    printf("Reversed string: %s",str);

    return 0;
}