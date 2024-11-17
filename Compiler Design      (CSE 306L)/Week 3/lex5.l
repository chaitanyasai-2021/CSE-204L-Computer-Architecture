%%
[0-9][0-9][0-9][0-9][0-9] { printf("string accepted\n"); }
[0-9]+ { printf("string rejected\n"); }
. { printf("string rejected\n"); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
