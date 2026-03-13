expr.l
%{
extern int yylval;
%}
%%
[0-9]+ { yylval=atoi(yytext); return NUMBER; }
\n { return NL ;}
. { return yytext[0]; }
%%
int yywrap()
{
return 1;
}

expr.y
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER NL
%left ‘+’ ‘-‘
%left ‘*’ ‘/’
%%
stmt : exp NL { printf(“Value = %d\n”,$1); exit(0);} ;
exp : exp ‘+’ exp { $$=$1+$3; }
| exp ‘-‘ exp { $$=$1-$3; }
| exp ‘*’ exp { $$=$1*$3; }
| exp ‘/’ exp { if($3==0) { printf(“Cannot divide by 0”); exit(0); } else $$=$1/$3; }
| ‘(‘ exp ‘)’ { $$=$2; }
| NUMBER { $$=$1; } ;
%%
int yyerror(char *msg)

{
printf(“Invalid Expression\n”);
exit(0);
}
#include "lex.yy.c"
main ()
{
printf(“Enter the expression\n”);
yyparse();
}
