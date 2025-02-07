#include<stdio.h>
int main()
{
    int n,i,j;
    printf("enter a number n to be divisible by number j\n");
    scanf("%d%d",&n,&j);
    i=n/j;
    printf("\n quotient is %d",i);
    i=n%j;
    printf("\n remainder is %d",i);
    return 0;
}
