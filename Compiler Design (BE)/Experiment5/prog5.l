%{
#include <stdio.h>
#include <stdlib.h>
float sum = 0.0;
int count = 0;
int expected_count = 0;
%}
%option noyywrap
%%
[0-9]+(.[0-9]+)? {
if (count < expected_count) {
sum += atof(yytext);
count++;
    if (count == expected_count) {
        float average = sum / expected_count;
        printf("\n--- Final Result ---\n");
        printf("Expected Terms: %d\n", expected_count);
        printf("Total Sum: %.2f\n", sum);
        printf("Calculated Average: %.4f\n", average);
        printf("--------------------\n"); 
        exit(0);
    }
}
}
.|\n ;
%%

int main(void) {
printf("Enter the number of terms (N) you wish to average: ");
if (scanf("%d", &expected_count) != 1 || expected_count <= 0) {
    fprintf(stderr, "Invalid number of terms entered. Exiting.\n");
    return 1;
}
while (getchar() != '\n');
printf("Enter the %d numbers separated by spaces or newlines: \n", expected_count);
yylex();
if (count < expected_count) {
    printf("\nWarning: Only %d out of %d numbers were processed before input ended.\n", count, expected_count);
}
return 0;
}
