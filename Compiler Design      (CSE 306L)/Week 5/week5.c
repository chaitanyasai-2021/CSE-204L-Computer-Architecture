/*
Week 5: Lexical Analyzer
5. Lab Assignment:
Consider the following mini Language, a simple procedural high-level language, only
operating on integer data, with a syntax looking vaguely like a simple C crossed with
Pascal. The syntax of the language is definedby the following BNF grammar:

&lt;program&gt; ::= &lt;block&gt;
&lt;block&gt; ::= { &lt;variabledefinition&gt; &lt;slist&gt; } | { &lt;slist&gt; }

&lt;variabledefinition&gt; ::= int&lt;vardeflist&gt;;
&lt;vardeflist&gt; ::= &lt;vardec&gt; | &lt;vardec&gt;, &lt;vardeflist&gt;
&lt;vardec&gt; ::= &lt;identifier&gt; | &lt;identifier&gt; [ &lt;constant&gt; ]
&lt;slist&gt; ::= &lt;statement&gt; | &lt;statement&gt;; &lt;slist&gt;
&lt;statement&gt; ::= &lt;assignment&gt; | &lt;ifstatement&gt; | &lt;whilestatement&gt; | &lt;block&gt; | &lt;printstatement&gt; |
&lt;empty&gt;
&lt;assignment&gt; ::= &lt;identifier&gt; = &lt;expression&gt; | &lt;identifier&gt; [ &lt;expression&gt; ] = &lt;expression&gt;
&lt;ifstatement&gt; ::= &lt;bexpression&gt; then &lt;slist&gt; else &lt;slist&gt; endif | if &lt;bexpression&gt; then &lt;slist&gt;
endif
&lt;whilestatement&gt; ::= while &lt;bexpression&gt; do &lt;slist&gt; enddo
&lt;printstatement&gt; ::= print ( &lt;expression&gt; )
&lt;expression&gt; ::= &lt;expression&gt; &lt;additionop&gt; &lt;term&gt; | &lt;term&gt; | addingop&gt; &lt;term&gt;
&lt;bexpression&gt; ::= &lt;expression&gt; &lt;relop&gt; &lt;expression&gt;
&lt;relop&gt; ::= &lt; | &lt;= | == | &gt;= | &gt; | !=
&lt;addingop&gt; ::= + | -
&lt;term&gt; ::= &lt;term&gt;&lt;mulitop&gt; &lt;factor&gt; | &lt;factor&gt;
&lt;multop&gt; ::= * | /
&lt;factor&gt; ::= &lt;constant&gt; | &lt;identifier&gt; | &lt;identifier&gt; [ &lt;expression&gt; ] | ( &lt;expression&gt; )
&lt;constant&gt; ::= &lt;digit&gt; | &lt;digit&gt; &lt;constant&gt;
&lt;identifier&gt; ::= &lt;identifier&gt; &lt;letterordigit&gt; | &lt;letter&gt;
&lt;letterordigit&gt; ::= &lt;letter&gt; | &lt;digit&gt;
&lt;letter&gt; ::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z
&lt;digit&gt; ::= 0|1|2|3|4|5|6|7|8|9
&lt;empty&gt; has the obvious meaning
Comments (zero or more characters enclosed between the standard C / Java style comment
brackets) can be inserted. The language has rudimentary support for 1-dimensional arrays.
The declaration int a[3] declares an array of three elements, referenced as a[0], a[1] and a[2]. Note
also that you should worry about the scoping of names.

A simple program written in this language is:
{ int a[3], t1, t2;
t1 = 2; a[0] = 1; a[1] = 2; a[t1] = 3;

t2 = -(a[2] + t1 * 6)/ a[2] -t1);
if t2 &gt; 5 then
print(t2);
else {
int t3;
t3 = 99;
t2 = -25;
print(-t1 + t2 * t3);
} endif
}
Design a Lexical analyser for the above language. The lexical analyser should ignore redundant
spaces, tabs, and newlines. It should also ignore comments. Although the syntax specification
states that identifiers can be arbitrarily long, you may restrict the length to some reasonable value.
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 100

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char cur_char;
    while ((cur_char = fgetc(inputFile)) != EOF) {
        if (cur_char == '(' || cur_char == ')') {
            fprintf(outputFile, "Punctuation: %c\n", cur_char);
        } else if (cur_char == ':') {
            char next_char = fgetc(inputFile);
            if (next_char == '=') {
                fprintf(outputFile, "Assign\n");
            } else {
                fprintf(outputFile, "Error: Invalid token\n");
            }
        } else if (isdigit(cur_char)) {
           
            int value = cur_char - '0';
            char next_char;
            while (isdigit(next_char = fgetc(inputFile))) {
                value = value * 10 + (next_char - '0');
            }
            ungetc(next_char, inputFile);
            fprintf(outputFile, "Integer: %d\n", value);
        } else if (cur_char == '<' || cur_char == '>' || cur_char == '=') {
            char next_char = fgetc(inputFile);
            if (next_char == '=') {
                fprintf(outputFile, "Relational Operator: %c=\n", cur_char);
            } else {
                ungetc(next_char, inputFile);
                fprintf(outputFile, "Relational Operator: %c\n", cur_char);
            }
        } else if (cur_char == '!') {
            char next_char = fgetc(inputFile);
            if (next_char == '=') {
                fprintf(outputFile, "Relational Operator: !=\n");
            } else {
                fprintf(outputFile, "Error: Invalid token\n");
            }
        } else if (cur_char == '/') {
            char next_char = fgetc(inputFile);
            if (next_char == '/') {
                while ((next_char = fgetc(inputFile)) != '\n') {
                
                }
            } else if (next_char == '*') {
                int commentEnded = 0;
                char prev_char = ' ';
                while (!commentEnded && (next_char = fgetc(inputFile)) != EOF) {
                    if (prev_char == '*' && next_char == '/') {
                        commentEnded = 1;
                    }
                    prev_char = next_char;
                }
            } else {
                ungetc(next_char, inputFile);
                fprintf(outputFile, "Divide Operator: /\n");
            }
        } else if (isalpha(cur_char) || cur_char == '_') {
           
            char identifier[MAX_IDENTIFIER_LENGTH];
            int i = 0;
            identifier[i++] = cur_char;
            while (isalnum(cur_char = fgetc(inputFile)) || cur_char == '_') {
                identifier[i++] = cur_char;
            }
            identifier[i] = '\0';
            ungetc(cur_char, inputFile);

            fprintf(outputFile, "Identifier: %s\n", identifier);
        } else if (cur_char == '+' || cur_char == '-') {
            
            fprintf(outputFile, "Arithmetic Operator: %c\n", cur_char);
        } else if (cur_char == '\n' || cur_char == ' ' || cur_char == '\t') {
           
        } else {
            fprintf(outputFile, "Error: Invalid token\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Lexical analysis completed. Check output.txt for results.\n");

    return 0;
}