#include <stdio.h>
#include <string.h>

void decimalToBase(int decimalNumber, int base, char *result)
{
    if (base < 2 || base > 16)
    {
        printf("Base must be between 2 and 16.\n");
        return;
    }

    const char digits[] = "0123456789ABCDEF"; // Digits for base representation
    int index = 0;
    int isNegative = 0;

    // Handle negative numbers for base 10
    if (decimalNumber < 0 && base == 10)
    {
        isNegative = 1;
        decimalNumber = -decimalNumber;
    }

    // Convert decimal to the desired base
    do
    {
        result[index++] = digits[decimalNumber % base];
        decimalNumber /= base;
    } while (decimalNumber > 0);

    // Add negative sign if applicable
    if (isNegative)
    {
        result[index++] = '-';
    }

    result[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct order
    for (int i = 0; i < index / 2; i++)
    {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }
}

int main()
{
    int decimalNumber, base;
    char result[33]; // Enough to hold binary representation of a 32-bit integer

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base (2 to 16): ");
    scanf("%d", &base);

    decimalToBase(decimalNumber, base, result);
    printf("Converted number: %s\n", result);

    return 0;
}
