#include <stdio.h>
#include <string.h>
// Lexical Analysis
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    ASSIGN,
    ARITHMETIC,
    END
};
struct Token {
    enum TokenType type;
    char lexeme[20];
};
struct Symbol {
    char name[20];
    char type[20];
};
struct Token currentToken;
struct Token getNextToken() {
    struct Token token;
    scanf("%s", token.lexeme);
    if (strcmp(token.lexeme, "int") == 0) {
        token.type = KEYWORD;
    } else if (strcmp(token.lexeme, "=") == 0) {
        token.type = ASSIGN;
    } else if (strcmp(token.lexeme, "+") == 0 || strcmp(token.lexeme, "-") == 0 ||
               strcmp(token.lexeme, "*") == 0 || strcmp(token.lexeme, "/") == 0) {
        token.type = ARITHMETIC;
    } else if (strcmp(token.lexeme, ";") == 0) {
        token.type = END;
    } else {
        token.type = IDENTIFIER;
    }
    return token;
}
// Symbol Table
void SymbolTable(struct Token tokens[]) {
    printf("Making Symbol Table...\n");
    struct Symbol symbolTable[100];  
    int symbolCount = 0;
    for (int i = 0; tokens[i].type != END; ++i) {
        struct Token token = tokens[i];
        if (token.type == IDENTIFIER) {
            int found = 0;
            for (int j = 0; j < symbolCount; ++j) {
                if (strcmp(symbolTable[j].name, token.lexeme) == 0) {
                    found = 1;
                    break;

                }
            }
            if (!found) {
                strcpy(symbolTable[symbolCount].name, token.lexeme);
                strcpy(symbolTable[symbolCount].type, "int");  
                symbolCount++;
            }
        }
    }
// Output the symbol table
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolCount; ++i) {
        printf("Name: %s, Type: %s\n", symbolTable[i].name, symbolTable[i].type);
    }
}
// Intermediate Code Generation
struct IntermediateCode {
    char operation[20];
    char arg1[20];
    char arg2[20];
    char result[20];
};
struct IntermediateCode intermediateCode[100];
int intermediateCodeCount = 0;
void addIntermediateCode(const char* operation, const char* arg1, const char* arg2, const char* result) {
    if (intermediateCodeCount < 100) {
        strcpy(intermediateCode[intermediateCodeCount].operation, operation);
        strcpy(intermediateCode[intermediateCodeCount].arg1, arg1);
        strcpy(intermediateCode[intermediateCodeCount].arg2, arg2);
        strcpy(intermediateCode[intermediateCodeCount].result, result);
        intermediateCodeCount++;
    } else {
        printf("Error: Intermediate code array is full.\n");
    }
}
void IntermediateCode(struct Token tokens[]) {
    printf("Generating Intermediate Code.....\n");
    struct Token token;
    char currentIdentifier[20];
    for (int i = 0; tokens[i].type != END; ++i) {
        token = tokens[i];
        if (token.type == IDENTIFIER) {
            strcpy(currentIdentifier, token.lexeme);
        } else if (token.type == ARITHMETIC) {
            char operation[20];
            strcpy(operation, token.lexeme);
            token = tokens[++i];  
            char operand[20];
            strcpy(operand, token.lexeme);
            char resultIdentifier[20];
            sprintf(resultIdentifier, "t%d", intermediateCodeCount);
            addIntermediateCode(operation, currentIdentifier, operand, resultIdentifier);
            strcpy(currentIdentifier, resultIdentifier);
        }
    }
    addIntermediateCode("=", currentIdentifier, "", "a");
    printf("Intermediate Code:\n");
    for (int i = 0; i < intermediateCodeCount; ++i) {
        printf("%s %s %s %s\n",
               intermediateCode[i].operation,
               intermediateCode[i].arg1,
               intermediateCode[i].arg2,
               intermediateCode[i].result);
    }
}
void AssemblyCode() {
    printf("Generating Assembly Code.....\n");
    for (int i = 0; i < intermediateCodeCount; ++i) {
        printf("MOV R1, %s\n", intermediateCode[i].arg1);
        printf("MOV R2, %s\n", intermediateCode[i].arg2);
        if (strcmp(intermediateCode[i].operation, "+") == 0) {
            printf("ADD R1, R2\n");
        }
        printf("STF %s, R1\n", intermediateCode[i].result);
    }
}
int main() {
    struct Token tokens[100];
    int tokenCount = 0;
    do {
        tokens[tokenCount] = getNextToken();
        tokenCount++;
    } while (tokens[tokenCount - 1].type != END && tokenCount < 100);
    printf("Performing Lexical Analysis...\n");
    for (int i = 0; i < tokenCount; ++i) {
        struct Token token = tokens[i];
        switch (token.type) {
            case KEYWORD:
                printf("keyword, %s\n", token.lexeme);
                break;
            case IDENTIFIER:
                printf("identifier, %s\n", token.lexeme);
                break;
            case ASSIGN:
                printf("assign, %s\n", token.lexeme);
                break;
            case ARITHMETIC:
                printf("arithmetic, %s\n", token.lexeme);
                break;
            case END:
                printf("end\n");
                break;
        }
    }
    SymbolTable(tokens);
    IntermediateCode(tokens);
    AssemblyCode();
    return 0;
}