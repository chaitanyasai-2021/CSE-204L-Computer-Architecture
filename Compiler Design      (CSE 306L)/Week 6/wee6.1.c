
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lookahead; 
int index = 0;

void error() {
    printf("Syntax error\n");
    exit(1);
}

void match(char expected) {
    if (lookahead == expected) {
        lookahead = getchar();
    } else {
        error();
    }
}

void E();
void EPrime();
void T();
void TPrime();
void F();

int main() {
    printf("Enter an expression: ");
    lookahead = getchar();
    E(); // Start parsing from the top-level expression
    if (lookahead == '\n') {
        printf("Syntax is correct.\n");
    } else {
        error();
    }
    return 0;
}

void E() {
    T();
    EPrime();
}

void EPrime() {
    if (lookahead == '+') {
        match('+');
        T();
        EPrime();
    }
}

void T() {
    F();
    TPrime();
}

void TPrime() {
    if (lookahead == '*') {
        match('*');
        F();
        TPrime();
    }
}

void F() {
    if (lookahead == '(') {
        match('(');
        E();
        match(')');
    } else if (isdigit(lookahead)) {
        match(lookahead);
    } else {
        error();
    }
}