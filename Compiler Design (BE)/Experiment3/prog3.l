%{
#include <stdio.h>
#include <stdlib.h>
void dec_to_hex(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    char hex_char[] = "0123456789abcdef";
    char hex_num[50];
    int i = 0;
    printf("Hexadecimal number is: \n");
    while (n > 0) {
        int remainder = n % 16;
        hex_num[i] = hex_char[remainder];
        n = n / 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex_num[j]);
    }
}
int yywrap(void) {
    return 1;
}
%}
%%
[0-9]+ {
    int dec_val = atoi(yytext);
    dec_to_hex(dec_val);
}
.|\n {
    printf("%s", yytext);
}
%%
int main(void) {
    printf("Enter a decimal number: \n");
    yylex();
    return 0;
}
