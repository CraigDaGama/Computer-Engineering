#include <stdio.h>

int main()
{
    int count = 0, n;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        n /= 10;
        count++;
    }

    printf("The number of digits in the entered number is: %d\n", count);
    return 0;
}
