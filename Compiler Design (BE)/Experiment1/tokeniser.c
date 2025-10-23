#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// List of some common keywords in C
const char *keywords[] = {
    "int", "float", "if", "else", "while", "for", "return", "char", "double", "void"
};
int numKeywords = 10;

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/=%><!";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

// Function to check if a character is a separator
int isSeparator(char ch) {
    char separators[] = "();,{}[]";
    for (int i = 0; i < strlen(separators); i++) {
        if (ch == separators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fptr;
    char line[300]; // Read each line from file

    fptr = fopen("file.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr) != NULL) {
        int i = 0;
        while (line[i] != '\0') {
            if (isspace(line[i])) {
                i++;
                continue;
            }

            // Identifiers or Keywords
            if (isalpha(line[i]) || line[i] == '_') {
                char word[50];
                int j = 0;
                while (isalnum(line[i]) || line[i] == '_') {
                    word[j++] = line[i++];
                }
                word[j] = '\0';
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
            }

            // Numbers
            else if (isdigit(line[i])) {
                char num[50];
                int j = 0;
                while (isdigit(line[i]) || line[i] == '.') {
                    num[j++] = line[i++];
                }
                num[j] = '\0';
                printf("Literal (Number): %s\n", num);
            }

            // String literal
            else if (line[i] == '"') {
                char str[100];
                int j = 0;
                str[j++] = line[i++];
                while (line[i] != '"' && line[i] != '\0') {
                    str[j++] = line[i++];
                }
                if (line[i] == '"') str[j++] = line[i++];
                str[j] = '\0';
                printf("Literal (String): %s\n", str);
            }

            // Character literal
            else if (line[i] == '\'') {
                char ch[10];
                int j = 0;
                ch[j++] = line[i++];
                while (line[i] != '\'' && line[i] != '\0') {
                    ch[j++] = line[i++];
                }
                if (line[i] == '\'') ch[j++] = line[i++];
                ch[j] = '\0';
                printf("Literal (Character): %s\n", ch);
            }

            // Operators
            else if (isOperator(line[i])) {
                printf("Operator: %c\n", line[i]);
                i++;
            }

            // Separators
            else if (isSeparator(line[i])) {
                printf("Separator: %c\n", line[i]);
                i++;
            }

            // Unknown tokens
            else {
                printf("Unknown Token: %c\n", line[i]);
                i++;
            }
        }
    }

    fclose(fptr);
    return 0;
}
