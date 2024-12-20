#include <stdio.h>

// Function prototypes
int fibonacci(int n);
int gcd(int a, int b);
int factorial(int n);
int reverseNumber(int n);
int sumOfDigits(int n);
void findDivisors(int n);

int main() {
    int choice, n, a, b;

    do {
        printf("\nMenu:\n");
        printf("1. Generate Fibonacci Number\n");
        printf("2. Find GCD of Two Numbers\n");
        printf("3. Find Factorial\n");
        printf("4. Find Reverse of a Number\n");
        printf("5. Find Sum of Digits of a Number\n");
        printf("6. Find Divisors of a Number\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position of the Fibonacci number: ");
                scanf("%d", &n);
                printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Reverse of %d is %d\n", n, reverseNumber(n));
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Sum of digits of %d is %d\n", n, sumOfDigits(n));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%d", &n);
                findDivisors(n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int reverseNumberHelper(int n, int reversed) {
    if (n == 0)
        return reversed;
    return reverseNumberHelper(n / 10, reversed * 10 + n % 10);
}

int reverseNumber(int n) {
    return reverseNumberHelper(n, 0);
}

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

void findDivisorsHelper(int n, int i) {
    if (i > n)
        return;
    if (n % i == 0)
        printf("%d ", i);
    findDivisorsHelper(n, i + 1);
}

void findDivisors(int n) {
    printf("Divisors of %d: ", n);
    findDivisorsHelper(n, 1);
    printf("\n");
}