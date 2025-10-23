%{
#include<stdio.h>
%}

%%
[0-9]+ printf("%s is a integer \n",yytext);
[0-9]+\.[0-9]+ printf("%s is a real number \n",yytext);
[a-zA-Z]+ printf("%s is a word \n",yytext);
.* printf("Invalid input \n");
%%

int main()
{
printf("Enter an input: \n");
yylex();
return 0;
}
int yywrap()
{
return 1;
}
