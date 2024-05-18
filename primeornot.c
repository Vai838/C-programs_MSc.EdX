#include <stdio.h>

int main() {
    int num, isPrime = 1;  // Assume the number is prime initially

    // Input the number to check
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for prime
    if (num <= 1) {
        isPrime = 0;  // Numbers less than or equal to 1 are not prime
    } else {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = 0;  // If divisible by any number other than 1 and itself, not prime
                break;
            }
        }
    }

    // Output the result
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
