// #include <tokens.h>

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void tok_append(char* tok, char c) {
    int len = strlen(tok);
    tok[len] = c;
    tok[len + 1] = '\0';
}

char lex(FILE* f) {
    char ch;
    char tok[51] = "";
    while ((ch = fgetc(f)) != EOF) {
        if (ch == ' ') {
            printf("%s\n", tok);
            /* lexer switch */
            strcpy(tok, "");
        }

        tok_append(tok, ch);

        // limit token length to 50 characters
        if (strlen(tok) > 50) {
            printf("\nObject names may not exceed 50 characters in length.\n");
            exit(1);
        }
    }

    return 0;
}

int main() {
    char fname[] = "tests/hello.txt";

    FILE* file_ptr = fopen(fname, "r");

    if (file_ptr == NULL) {
        printf("Error opening file: %s", fname);
        exit(1);
    }

    lex(file_ptr);

    fclose(file_ptr);

    return 0;
}