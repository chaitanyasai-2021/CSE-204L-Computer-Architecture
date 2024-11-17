%{
int num_lines=0;
%}

%%
\n  {++num_lines;}
.  
%%


int main()
{
    yylex();
    printf("Number of lines: %d\n", num_lines);
    return 0;
}

int yywrap()
{
    return 1;
}
