#include <stdio.h>

int main(void)
{
    int numerator, denominator;
    int m, n, remainder, gcd;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    if (denominator == 0) {
        printf("Error: Denominator cannot be zero.\n");
        return 1;
    }

    m = numerator;
    n = denominator;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    if (gcd < 0) {
        gcd = -gcd;
    }

    numerator = numerator / gcd;
    denominator = denominator / gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    printf("In lowest terms: %d/%d\n", numerator, denominator);

    return 0;
}
