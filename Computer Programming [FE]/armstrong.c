#include <stdio.h>
#include <math.h>

int main()
{
    int i, num, sum, count, temp;

    printf("All Armstrong numbers between 1 and 1000 are:\n");

    for (i = 1; i <= 1000; i++) {
        num = i;
        count = (int)log10(num) + 1; // Calculate number of digits
        sum = 0;
        temp = num;

        while (temp != 0) {
            sum += pow(temp % 10, count);
            temp /= 10;
        }

        if (sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
