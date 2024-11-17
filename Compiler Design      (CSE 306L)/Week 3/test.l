%{
#include <stdio.h>
%}

%%
[aeiouAEIOU] { printf("Vowel: %s\n", yytext); }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] { printf("Consonant: %s\n", yytext); }
[0123456789] { printf("Digit: %s\n", yytext); }
["00"] { printf("Consecutive zeroes: %s\n", yytext); }
%%


int yywrap() {}

int main() {
    yylex();
    return 0;
}