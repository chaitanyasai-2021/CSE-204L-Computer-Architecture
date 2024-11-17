// week 7
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROD 10
#define MAX_LEN 10

// Function to check if a character is a terminal or not
int isTerminal(char c) {
    return islower(c) || c == '#'; // Considering lowercase letters as terminals, # represents epsilon
}

// Function to add a character to a set
void addToSet(char set[], char c) {
    int i;
    for (i = 0; set[i] != '\0'; i++) {
        if (set[i] == c) {
            return;
        }
    }
    set[i] = c;
    set[i + 1] = '\0';
}

// Function to compute FIRST set for a given non-terminal
void computeFirst(char first[], char grammar[][MAX_LEN], char nonTerm) {
    int i;
    for (i = 0; i < MAX_PROD; i++) {
        if (grammar[i][0] == nonTerm) {
            if (isTerminal(grammar[i][2])) {
                addToSet(first, grammar[i][2]);
            } else {
                computeFirst(first, grammar, grammar[i][2]);
            }
        }
    }
}

// Function to compute FOLLOW set for a given non-terminal
void computeFollow(char follow[], char grammar[][MAX_LEN], char nonTerm) {
    int i, j;
    for (i = 0; i < MAX_PROD; i++) {
        for (j = 2; j < strlen(grammar[i]); j++) {
            if (grammar[i][j] == nonTerm) {
                if (j + 1 < strlen(grammar[i])) {
                    if (isTerminal(grammar[i][j + 1])) {
                        addToSet(follow, grammar[i][j + 1]);
                    } else {
                        char first[MAX_LEN] = "";
                        computeFirst(first, grammar, grammar[i][j + 1]);
                        int k;
                        for (k = 0; k < strlen(first); k++) {
                            if (first[k] != '#') {
                                addToSet(follow, first[k]);
                            } else {
                                computeFollow(follow, grammar, grammar[i][0]);
                            }
                        }
                    }
                } else if (j + 1 == strlen(grammar[i]) && grammar[i][0] != nonTerm) {
                    computeFollow(follow, grammar, grammar[i][0]);
                }
            }
        }
    }
}

int main() {
    char grammar[MAX_PROD][MAX_LEN];
    int n, i;
    char nonTerm;
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    
    printf("Enter the productions (Format: S->abc, A->def, ...):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", grammar[i]);
    }

    printf("Enter the non-terminal to compute FIRST and FOLLOW for: ");
    scanf(" %c", &nonTerm);

    char first[MAX_LEN] = "";
    computeFirst(first, grammar, nonTerm);
    
    char follow[MAX_LEN] = "";
    addToSet(follow, '$'); // $ represents end of input marker
    computeFollow(follow, grammar, nonTerm);

    printf("FIRST(%c) = {%s}\n", nonTerm, first);
    printf("FOLLOW(%c) = {%s}\n", nonTerm, follow);

    return 0;
}