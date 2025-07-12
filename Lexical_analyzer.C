#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {"int", "float", "if", "else", "while", "do", "return", "break", "for", "char"};

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[20];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");

    while ((ch = fgetc(fp)) != EOF) {
        // If character is alphabet or digit, collect the word
        if (isalnum(ch)) {
            word[i++] = ch;
        } else {
            word[i] = '\0';
            i = 0;

            if (strlen(word) > 0) {
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
            }

            // Check for operators
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
                ch == '=' || ch == '<' || ch == '>' || ch == '!') {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
