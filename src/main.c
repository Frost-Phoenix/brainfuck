#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define TRUE 1
#define FALSE 0

#define MEMORY_NB_BYTES 30000


static int _valid_char(char c) {
    return c == '+' || c == '-' || c == '<' || c == '>' || c == '[' || c == ']' || c == '.' || c == ',';
}

int main(int argc, char* argv []) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint8_t memory[MEMORY_NB_BYTES] = { 0 };
    uint8_t* p = memory;

    FILE* fp;
    int c;

    fp = fopen(argv[1], "rt");
    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (!_valid_char(c)) {
            continue;
        }

        switch (c) {
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '>':
                p++;
                break;
            case '<':
                (*p)--;
                break;

        }
    }

    printf("\n");
    fclose(fp);

    return EXIT_SUCCESS;
}
