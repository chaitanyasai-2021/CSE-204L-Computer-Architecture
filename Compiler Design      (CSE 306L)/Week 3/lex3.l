

%{
int vowel_count = 0;
int consonant_count = 0;
%}

%%
[aAeEiIoOuU] { vowel_count++; }
[A-Za-z]    { consonant_count++; }
.           { /* Do nothing for other characters */ }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);
    return 0;
}
